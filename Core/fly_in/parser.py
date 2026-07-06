"""Parser for Fly-in map files."""

from __future__ import annotations

import re
from dataclasses import dataclass

from models import Edge, Graph, Zone, ZoneType


class ParseError(ValueError):
    """Map parsing error with explicit message."""


@dataclass(frozen=True)
class LineInfo:
    """Line wrapper used for better error reporting."""

    number: int
    text: str


ZONE_PATTERN = re.compile(
    r"^(start_hub|end_hub|hub):\s+([^\s\-]+)\s+(-?\d+)\s+(-?\d+)\s*(.*)$"
)
CONNECTION_PATTERN = re.compile(
    r"^connection:\s+([^\s\-]+)-([^\s\-]+)\s*(.*)$"
)
DRONES_PATTERN = re.compile(r"^nb_drones:\s+(\d+)\s*$")
META_PATTERN = re.compile(r"^\[(.*)\]\s*$")


def _strip_comments(raw: str) -> str:
    """Remove comments starting with '#' and strip surrounding whitespace.

    Args:
        raw: The raw input line.

    Returns:
        The cleaned line with comments removed and whitespaces trimmed.
    """
    idx = raw.find("#")
    if idx == -1:
        return raw.strip()
    return raw[:idx].strip()


def _parse_meta(meta_raw: str, line_no: int) -> dict[str, str]:
    """Parse metadata key-value pairs enclosed in brackets.

    Args:
        meta_raw: The raw metadata string, e.g., '[zone=normal color=blue]'.
        line_no: The line number in the file for error reporting.

    Returns:
        A dictionary mapping metadata keys to values.

    Raises:
        ParseError: If the metadata syntax is invalid.
    """
    if not meta_raw:
        return {}
    match = META_PATTERN.match(meta_raw.strip())
    if not match:
        raise ParseError(f"line {line_no}: invalid metadata syntax")
    body = match.group(1).strip()
    if not body:
        return {}
    result: dict[str, str] = {}
    for part in body.split():
        if "=" not in part:
            raise ParseError(f"line {line_no}: invalid metadata item '{part}'")
        key, value = part.split("=", 1)
        if not key or not value:
            raise ParseError(f"line {line_no}: invalid metadata item '{part}'")
        result[key] = value
    return result


def parse_map(path: str) -> Graph:
    """Parse map file into a Graph object."""
    with open(path, "r", encoding="utf-8") as handle:
        raw_lines = [
            LineInfo(i + 1, _strip_comments(line))
            for i, line in enumerate(handle)
        ]

    lines = [li for li in raw_lines if li.text]
    if not lines:
        raise ParseError("line 1: empty map")

    drones_match = DRONES_PATTERN.match(lines[0].text)
    if not drones_match:
        raise ParseError(
            "line 1: first line must be 'nb_drones: <positive_integer>'"
        )
    nb_drones = int(drones_match.group(1))
    if nb_drones <= 0:
        raise ParseError("line 1: nb_drones must be a positive integer")

    graph = Graph(nb_drones=nb_drones)
    start_seen = False
    end_seen = False

    for line in lines[1:]:
        zone_match = ZONE_PATTERN.match(line.text)
        if zone_match:
            hub_type, name, sx, sy, meta_raw = zone_match.groups()
            if name in graph.zones:
                raise ParseError(
                    f"line {line.number}: duplicate zone '{name}'"
                )
            meta = _parse_meta(meta_raw, line.number)

            zone_type_str = meta.get("zone", "normal")
            if zone_type_str not in {z.value for z in ZoneType}:
                raise ParseError(
                    f"line {line.number}: invalid zone type '{zone_type_str}'"
                )
            zone_type = ZoneType(zone_type_str)
            color = meta.get("color", "none")

            max_drones_raw = meta.get("max_drones", "1")
            if not max_drones_raw.isdigit() or int(max_drones_raw) <= 0:
                raise ParseError(
                    f"line {line.number}: max_drones must be positive integer"
                )
            max_drones = int(max_drones_raw)

            is_start = hub_type == "start_hub"
            is_end = hub_type == "end_hub"
            if is_start:
                if start_seen:
                    raise ParseError(
                        f"line {line.number}: duplicate start_hub"
                    )
                start_seen = True
            if is_end:
                if end_seen:
                    raise ParseError(f"line {line.number}: duplicate end_hub")
                end_seen = True

            graph.add_zone(
                Zone(
                    name=name,
                    x=int(sx),
                    y=int(sy),
                    zone_type=zone_type,
                    color=color,
                    max_drones=max_drones,
                    is_start=is_start,
                    is_end=is_end,
                )
            )
            continue

        conn_match = CONNECTION_PATTERN.match(line.text)
        if conn_match:
            a, b, meta_raw = conn_match.groups()
            if a not in graph.zones or b not in graph.zones:
                raise ParseError(
                    f"line {line.number}: connection references unknown zone"
                )
            meta = _parse_meta(meta_raw, line.number)
            max_link_raw = meta.get("max_link_capacity", "1")
            if not max_link_raw.isdigit() or int(max_link_raw) <= 0:
                raise ParseError(
                    f"line {line.number}: "
                    "max_link_capacity must be positive integer"
                )
            edge = Edge(a=a, b=b, max_link_capacity=int(max_link_raw))
            if edge.key in graph.edges:
                raise ParseError(
                    f"line {line.number}: duplicate connection '{a}-{b}'"
                )
            graph.add_edge(edge)
            continue

        raise ParseError(f"line {line.number}: unrecognized statement")

    if not start_seen:
        raise ParseError("missing start_hub")
    if not end_seen:
        raise ParseError("missing end_hub")
    return graph
