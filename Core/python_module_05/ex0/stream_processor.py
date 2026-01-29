"""
Exercise 0: Data Processor Foundation
Demonstrates method overriding and polymorphism.
"""
from abc import ABC, abstractmethod
from typing import Any, List


class DataProcessor(ABC):
    """Abstract base class for processing data."""

    def __init__(self) -> None:
        """Initialize processor."""
        pass

    @abstractmethod
    def process(self, data: Any) -> str:
        """Process data and return result string."""
        pass

    @abstractmethod
    def validate(self, data: Any) -> bool:
        """Validate if data is appropriate."""
        pass

    def format_output(self, result: str) -> str:
        """Format the output string."""
        return f"Output: {result}"


class NumericProcessor(DataProcessor):
    """Processes numeric lists."""

    def __init__(self) -> None:
        """Initialize numeric processor."""
        super().__init__()

    def validate(self, data: Any) -> bool:
        """Check if data is list of numbes."""
        try:
            if not isinstance(data, list):
                return False
            return all(isinstance(x, (int, float)) for x in data)
        except Exception:
            return False

    def process(self, data: Any) -> str:
        """Calculate stats."""
        if not self.validate(data):
            return "Invalid data"
        print("Validation: Numeric data verified")
        try:
            total = sum(data)
            avg = total / len(data) if data else 0
            return (f"Processed {len(data)} numeric values, "
                    f"sum={total}, avg={avg}")
        except Exception:
            return "Error processing data"


class TextProcessor(DataProcessor):
    """Processes text strings."""

    def __init__(self) -> None:
        """Initialize text processor."""
        super().__init__()

    def validate(self, data: Any) -> bool:
        """Check if data is string."""
        return isinstance(data, str)

    def process(self, data: Any) -> str:
        """Analyze text."""
        if not self.validate(data):
            return "Invalid data"
        print("Validation: Text data verified")
        words = len(data.split())
        return f"Processed text: {len(data)} characters, {words} words"


class LogProcessor(DataProcessor):
    """Processes log entries."""

    def __init__(self) -> None:
        """Initialize log processor."""
        super().__init__()

    def validate(self, data: Any) -> bool:
        """Check if data is string."""
        return isinstance(data, str)

    def process(self, data: Any) -> str:
        """Extract log level."""
        if not self.validate(data):
            return "Invalid data"
        print("Validation: Log entry verified")
        try:
            if ":" in data:
                level, msg = data.split(":", 1)
                if level == "ERROR":
                    return f"[ALERT] ERROR level detected:{msg}"
                return f"[{level}] {level} level detected:{msg}"
            return f"Log entry: {data}"
        except Exception:
            return "Error processing log"


def main() -> None:
    """Run data processor foundation demo."""
    try:
        print("=== CODE NEXUS - DATA PROCESSOR FOUNDATION ===")
        print()

        # 1. Individual Processing
        print("Initializing Numeric Processor...")
        num_proc = NumericProcessor()
        data1 = [1, 2, 3, 4, 5]
        print(f"Processing data: {data1}")
        print(num_proc.format_output(num_proc.process(data1)))
        print()

        print("Initializing Text Processor...")
        txt_proc = TextProcessor()
        data2 = "Hello Nexus World"
        print(f"Processing data: \"{data2}\"")
        print(txt_proc.format_output(txt_proc.process(data2)))
        print()

        print("Initializing Log Processor...")
        log_proc = LogProcessor()
        data3 = "ERROR: Connection timeout"
        print(f"Processing data: \"{data3}\"")
        print(log_proc.format_output(log_proc.process(data3)))
        print()

        # 2. Polymorphic Demo
        print("=== Polymorphic Processing Demo ===")
        print()

        print("Processing multiple data types through same interface...")

        processors: List[DataProcessor] = [
            NumericProcessor(),
            TextProcessor(),
            LogProcessor()
        ]

        datasets = [
            [1, 2, 3],
            "Hello World",
            "INFO: System ready"
        ]

        if len(processors) == len(datasets):
            res1 = processors[0].process(datasets[0])
            print(f"Result 1: {res1}")

            res2 = processors[1].process(datasets[1])
            print(f"Result 2: {res2}")

            res3 = processors[2].process(datasets[2])
            print(f"Result 3: {res3}")
        print()

        print("Foundation systems online. Nexus ready for advanced streams.")

    except Exception as e:
        print(f"System Error: {e}")


if __name__ == "__main__":
    main()
