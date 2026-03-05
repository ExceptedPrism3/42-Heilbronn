import sys
import json
import argparse
from pathlib import Path

from llm_sdk import Small_LLM_Model
from src.vocab import get_vocab_strings
from src.schema_compiler import SchemaCompiler
from src.generation import generate_constrained
from src.models import FunctionDefinitionList


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Constrained Decoding LLM for Function Calling"
    )
    parser.add_argument(
        "--input",
        default="data/input/function_calling_tests.json",
        help="Path to input prompts JSON",
    )
    parser.add_argument(
        "--output",
        default="data/output/function_calling_results.json",
        help="Path to write results JSON",
    )
    parser.add_argument(
        "--defs",
        default="data/input/function_definitions.json",
        help="Path to function definitions JSON",
    )
    args = parser.parse_args()

    # Load functions
    try:
        with open(args.defs, "r", encoding="utf-8") as f:
            functions_raw = json.load(f)
        functions = FunctionDefinitionList.model_validate(
            {"functions": functions_raw}
        )
    except Exception as e:
        print(f"Error loading function definitions: {e}")
        sys.exit(1)

    # Load prompts
    try:
        with open(args.input, "r", encoding="utf-8") as f:
            prompts = json.load(f)
        if not isinstance(prompts, list):
            raise ValueError(
                "Input file must contain a JSON array of objects."
            )
    except Exception as e:
        print(f"Error loading prompts from {args.input}: {e}")
        sys.exit(1)

    # Prepare model
    print("Loading model and vocabulary...")
    try:
        model = Small_LLM_Model(device="cpu")
        vocab_path = model.get_path_to_vocabulary_json()
        vocab_bytes = get_vocab_strings(vocab_path)
    except Exception as e:
        print(f"Error loading LLM: {e}")
        sys.exit(1)

    # Compile schema
    try:
        compiler = SchemaCompiler(functions)
        start_state = compiler.compile()
    except Exception as e:
        print(f"Error compiling constraints DFA: {e}")
        sys.exit(1)

    results = []
    print(f"Processing {len(prompts)} prompts...")

    for i, item in enumerate(prompts):
        if not isinstance(item, dict) or "prompt" not in item:
            print(f"Warning: prompt at index {i} is malformed. Skipping.")
            continue

        prompt_text = item["prompt"]
        print(f"[{i + 1}/{len(prompts)}] Generating for: {prompt_text}")

        # Format prompt to guide the LLM towards JSON function calling
        funcs_json_str = json.dumps(functions_raw, indent=2)
        formatted_prompt = (
            "<|im_start|>system\nYou are a reliable function-calling "
            "assistant. "
            f"You have access to the following functions:\n"
            f"{funcs_json_str}\n\n"
            "You must output ONLY a valid JSON object representing a "
            "function call. Start exactly with {\"fn_name\":...\n"
            "CRITICAL: If you need to write a regular expression,"
            " DO NOT use JavaScript "
            "regex delimiters like /.../g."
            " Just output the raw Python pattern. "
            "If your pattern requires backslashes"
            " (like \\w or \\b), you MUST double-escape "
            "them (e.g. \\\\w) because this is a JSON string.<|im_end|>\n"
            f"<|im_start|>user\n{prompt_text}<|im_end|>\n"
            "<|im_start|>assistant\n"
        )

        try:
            generated_str = generate_constrained(
                model,
                formatted_prompt,
                start_state,
                vocab_bytes,
                max_tokens=150,
            )
            print()
            parsed_json = json.loads(generated_str)

            # Combine into final structure
            final_obj = {
                "prompt": prompt_text,
                "fn_name": parsed_json["fn_name"],
                "args": parsed_json["args"],
            }
            results.append(final_obj)
        except Exception as e:
            import traceback

            traceback.print_exc()
            print(f"Error generating for prompt '{prompt_text}': {e}")
            # If a crash happens for one prompt, try to keep going
            # for reliability

    # Write output
    try:
        out_path = Path(args.output)
        out_path.parent.mkdir(parents=True, exist_ok=True)
        with open(out_path, "w", encoding="utf-8") as f:
            json.dump(results, f, indent=2)
        print(f"Successfully wrote {len(results)} results to {args.output}")
    except Exception as e:
        print(f"Error writing output to {args.output}: {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()
