from datetime import datetime
from enum import Enum
from pydantic import BaseModel, Field, model_validator, ValidationError


class ContactType(str, Enum):
    radio = "radio"
    visual = "visual"
    physical = "physical"
    telepathic = "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: str | None = Field(default=None, max_length=500)
    is_verified: bool = False

    @model_validator(mode='after')
    def check_business_rules(self) -> 'AlienContact':
        # 1. Contact ID Prefix
        if not self.contact_id.startswith("AC"):
            raise ValueError('Contact ID must start with "AC"')

        # 2. Physical Verified
        if self.contact_type == ContactType.physical and not self.is_verified:
            raise ValueError('Physical contact reports must be verified')

        # 3. Telepathic Witnesses
        if (self.contact_type == ContactType.telepathic
                and self.witness_count < 3):
            raise ValueError('Telepathic contact requires'
                             ' at least 3 witnesses')

        # 4. Strong Signals Message
        if self.signal_strength > 7.0 and not self.message_received:
            raise ValueError('Strong signals (> 7.0) should'
                             ' include received messages')

        return self


def main() -> None:
    print("Alien Contact Log Validation")
    print("=" * 40)

    try:
        # Valid contact
        log = AlienContact(
            contact_id="AC_2024_001",
            timestamp=datetime.now(),
            location="Area 51, Nevada",
            contact_type=ContactType.radio,
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=5,
            message_received="Greetings from Zeta Reticuli"
        )
        print("Valid contact report:")
        print(f"ID: {log.contact_id}")
        print(f"Type: {log.contact_type.value}")
        print(f"Location: {log.location}")
        print(f"Signal: {log.signal_strength}/10")
        print(f"Duration: {log.duration_minutes} minutes")
        print(f"Witnesses: {log.witness_count}")
        print(f"Message: '{log.message_received}'")

    except ValidationError as e:
        print(e)

    print("=" * 40)
    print("Expected validation error:")

    try:
        # Invalid: Telepathic < 3 witnesses
        AlienContact(
            contact_id="AC_2024_INVALID",
            timestamp=datetime.now(),
            location="Mind Palace",
            contact_type=ContactType.telepathic,
            signal_strength=2.0,
            duration_minutes=5,
            witness_count=1,  # Error
            is_verified=False
        )
    except ValidationError as e:
        for err in e.errors():
            msg = err.get('msg', '')
            if 'Value error,' in msg:
                msg = msg.replace('Value error, ', '')
            print(msg)


if __name__ == "__main__":
    main()
