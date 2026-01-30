from datetime import datetime
from enum import Enum
from pydantic import BaseModel, Field, model_validator, ValidationError


class Rank(str, Enum):
    cadet = "cadet"
    officer = "officer"
    lieutenant = "lieutenant"
    captain = "captain"
    commander = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = "planned"
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode='after')
    def validate_mission_safety(self) -> 'SpaceMission':
        # 1. Mission ID
        if not self.mission_id.startswith("M"):
            raise ValueError('Mission ID must start with "M"')

        # 2. Commander Requirement
        has_leader = any(
            m.rank in (Rank.captain, Rank.commander)
            for m in self.crew
        )
        if not has_leader:
            raise ValueError('Mission must have at least'
                             ' one Commander or Captain')

        # 3. Long Mission Experience
        if self.duration_days > 365:
            experienced_count = sum(1 for m in self.crew
                                    if m.years_experience >= 5)
            # Need 50% experienced
            if experienced_count < (len(self.crew) / 2):
                raise ValueError(
                    'Long missions (> 365 days) '
                    'need 50% experienced crew (5+ years)'
                )

        # 4. Active Status
        if not all(m.is_active for m in self.crew):
            raise ValueError('All crew members must be active')

        return self


def main() -> None:
    print("Space Mission Crew Validation")
    print("=" * 40)

    try:
        # Valid Mission
        cmdr = CrewMember(
            member_id="CM001", name="Sarah Connor", rank=Rank.commander,
            age=45, specialization="Mission Command", years_experience=20
        )
        nav = CrewMember(
            member_id="CM002", name="John Smith", rank=Rank.lieutenant,
            age=32, specialization="Navigation", years_experience=8
        )
        eng = CrewMember(
            member_id="CM003", name="Alice Johnson", rank=Rank.officer,
            age=28, specialization="Engineering", years_experience=4
        )

        mission = SpaceMission(
            mission_id="M2024_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            launch_date=datetime.now(),
            duration_days=900,
            crew=[cmdr, nav, eng],
            budget_millions=2500.0
        )

        print("Valid mission created:")
        print(f"Mission: {mission.mission_name}")
        print(f"ID: {mission.mission_id}")
        print(f"Destination: {mission.destination}")
        print(f"Duration: {mission.duration_days} days")
        print(f"Budget: ${mission.budget_millions}M")
        print(f"Crew size: {len(mission.crew)}")
        print("Crew members:")
        for m in mission.crew:
            print(f"- {m.name} ({m.rank.value}) - {m.specialization}")

    except ValidationError as e:
        print(e)

    print("=" * 40)
    print("Expected validation error:")

    try:
        # Invalid: No Commander
        cadet = CrewMember(
            member_id="CM004", name="Newbie", rank=Rank.cadet,
            age=20, specialization="Cleaning", years_experience=0
        )
        SpaceMission(
            mission_id="M2024_FAIL",
            mission_name="Doom Mission",
            destination="Sun",
            launch_date=datetime.now(),
            duration_days=10,
            crew=[cadet],  # Just one cadet
            budget_millions=10.0
        )
    except ValidationError as e:
        for err in e.errors():
            msg = err.get('msg', '')
            if 'Value error,' in msg:
                msg = msg.replace('Value error, ', '')
            print(msg)


if __name__ == "__main__":
    main()
