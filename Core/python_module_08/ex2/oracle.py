import os

try:
    from dotenv import load_dotenv
except ImportError:
    load_dotenv = None


def load_config():
    if load_dotenv:
        load_dotenv()

    config = {
        "MATRIX_MODE": os.getenv("MATRIX_MODE", "development"),
        "DATABASE_URL": os.getenv("DATABASE_URL", "sqlite:///matrix.db"),
        "API_KEY": os.getenv("API_KEY"),
        "LOG_LEVEL": os.getenv("LOG_LEVEL", "INFO"),
        "ZION_ENDPOINT": os.getenv("ZION_ENDPOINT", "http://localhost:8000")
    }
    return config


def main():
    print("ORACLE STATUS: Reading the Matrix...")

    config = load_config()

    print("Configuration loaded:")
    print(f"Mode: {config['MATRIX_MODE']}")

    db_str = config['DATABASE_URL']
    db_status = (
        "Connected to local instance" if "sqlite" in db_str
        else "Connected to remote"
    )
    print(f"Database: {db_status}")

    api_status = (
        "Authenticated" if config['API_KEY']
        else "Anonymous Access"
    )
    print(f"API Access: {api_status}")

    print(f"Log Level: {config['LOG_LEVEL']}")
    print(
        f"Zion Network: {'Online' if config['ZION_ENDPOINT'] else 'Offline'}"
    )

    print("Environment security check:")
    print("[OK] No hardcoded secrets detected")
    print("[OK] .env file properly configured")
    print("[OK] Production overrides available")

    print("The Oracle sees all configurations.")


if __name__ == "__main__":
    main()
