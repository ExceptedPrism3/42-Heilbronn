# Call me maybe
This project has been created as part of the 42 curriculum by [aben-cad](https://profile-v3.intra.42.fr/users/aben-cad)

# Introduction
This project implements a robust constrained decoding engine that forces a small language model (`Qwen3-0.6B`) to generate 100% valid JSON function calls strictly matching a provided schema.

## Description
The core objective is to prevent the LLM from outputting invalid JSON, hallucinating arguments, or generating syntax errors by intervening during the auto-regressive generation process. By evaluating the probability distribution of the next token (`logits`) and masking out any tokens that violate the target JSON structure, the LLM is deterministically guided down a valid structural path.

## Setup and Execution

1. **Prerequisites**: Python 3.10+ and the `uv` package manager must be installed.
2. **Installation**: 
   ```bash
   make install
   ```
   *Note: This utilizes `uv` to manage the virtual environment and install dependencies natively.*

3. **Running the Benchmarks**:
   ```bash
   make run
   ```
   This command executes the full testing suite on `data/exercise_input/function_calling_tests.json` and outputs evaluating results to `data/output/function_calling_results.json`.

4. **Code Quality**:
   ```bash
   make lint
   make lint-strict
   ```
   These commands run `flake8` and `mypy` strict type-checking on the `src/` directory to ensure PEP-8 compliance.

## Algorithm Explanation

The constrained decoding algorithm operates via a Non-deterministic Finite Automaton (NFA) state machine.

1. **Vocabulary Loading**: The 152k sub-token BPE vocabulary is loaded from `vocab.json`. Since the `transformers` library was disallowed for text parsing, a custom `bytes_to_unicode` BPE mapper was implemented (`src/vocab.py`) to accurately decode token representations back to their raw byte equivalents.
2. **Schema Compilation**: At startup, `functions_definition.json` is validated via strict Pydantic models (`src/models.py`). The `SchemaCompiler` then dynamically generates an NFA representing every valid JSON byte sequence that perfectly matches the schema format (`{"fn_name": "...", "args": {...}}`). 
3. **Logit Masking**: During generation (`src/generation.py`), the `ConstraintMasker` compares every token in the 152k vocabulary against the current NFA state. It filters the tokens down to only those that form valid byte-transitions within the JSON structure.
4. **Greedy Decoding**: The model's raw probability logits for the valid tokens are preserved, while all invalid tokens are assigned `-inf`. An `argmax` operation selects the most probable structurally valid token.
5. **Advancement**: The selected token's bytes are consumed to transition the NFA forward, and the sequence repeats until the JSON object is definitively closed.

## Design Decisions

- **Custom BPE Mapper**: Rather than relying on `transformers.AutoTokenizer`, an independent Byte-Pair Encoding translation dictionary was extracted from `vocab.json`. This meets the project constraint of minimizing external abstraction dependencies.
- **NFA Over Regex**: Regex parsing per-token is exceptionally slow for 152k vocabulary sizes. Compiling the schema into a state machine enables efficient byte-by-byte traversal.
- **Strict String Escaping Constraints**: Initially, the LLM attempted to output raw `\d` within regex generation. Because `\d` is an invalid JSON escape limit, the DFA blocked the token, forcing the model to pick the next highest probable valid escape (like `\b`), which derailed the generation into hallucination (e.g. `/\b233/`). Instead of allowing invalid JSON sequences, the System Prompt was modified with explicit instructions teaching the LLM to double-escape its regexes (`\\d`). The LLM successfully adapted, writing perfect Regex constraints while maintaining 100% syntactically valid JSON.

## Performance Considerations

- **Memoization (`src/dfa.py`)**: Traversal logic was heavily optimized using dictionary caching (`_valid_tokens_cache` and `_CONSUME_CACHE`). Precomputing the token validity dramatically reduced the filtering time across the massive 152k vocabulary.
- **PyTorch MPS Engine Bug**: Running inference via Apple Silicon's Metal Performance Shaders (`mps`) caused significant memory ballooning due to PyTorch caching computational graphs for every distinct sequence length. This consumed gigabytes of SSD space in under five minutes. The execution environment was securely restricted strictly to CPU inference (`model = Small_LLM_Model(device="cpu")`) to stabilize execution at the expense of computational bandwidth. Despite the slow CPU iteration speed, all 14 prompts validated successfully.

## Resources
Below is a curated list of classic references, official documentation, and technical articles directly related to constrained decoding, JSON validation, automata theory, tokenization, and structured generation.

### 1) Language Models & Constrained Decoding

- 📄 Language Models are Few-Shot Learners — OpenAI
(Brown et al., 2020)
Foundational GPT paper explaining autoregressive token generation and logits.

- 📄 Training language models to follow instructions with human feedback — OpenAI
(Ouyang et al., 2022)
Explains alignment and decoding behavior in instruction-tuned LLMs.

- 📄 Guided Generation / Logit Bias Documentation — OpenAI API Docs
Demonstrates practical token masking and constrained generation techniques.

- 📄 Structured Output from LLMs — Microsoft Research
Research on schema-constrained generation and deterministic decoding.

- 📄 “Outlines: Structured Text Generation” — Hugging Face
Open-source library implementing regex / grammar constrained decoding.

### 2) Automata Theory & Formal Languages

- 📘 Introduction to Automata Theory, Languages, and Computation — John Hopcroft, Rajeev Motwani, Jeffrey Ullman
The theoretical foundation for NFAs, DFAs, and state machine construction.

- 📘 Compilers: Principles, Techniques, and Tools — Alfred Aho, Monica Lam, Ravi Sethi, Jeffrey Ullman
Covers lexical analysis, parsing, and automata-based validation.

- These texts directly inspired the schema → NFA compilation strategy used in this project.

### 3) Tokenization & Byte Pair Encoding (BPE)

- 📄 Neural Machine Translation of Rare Words with Subword Units — Rico Sennrich et al. (2016)
Introduced BPE for neural models.

- 📄 GPT-2 Tokenizer Implementation — OpenAI
Reference implementation of bytes_to_unicode() used as inspiration for the custom BPE mapper.

- 🤗 Tokenizers Documentation — Hugging Face
Practical reference for tokenizer internals and vocabulary decoding.

### 4) JSON Specification & Validation

- 📜 The JSON Data Interchange Format (RFC 8259) — IETF
Authoritative specification defining valid JSON syntax and escape rules.

- 📄 Pydantic Documentation — Pydantic
Used for strict schema validation in src/models.py.

### 5) PyTorch & Inference Engineering

- 📘 PyTorch Documentation — PyTorch
Used for logits extraction and inference.

- 📄 Apple Metal Performance Shaders (MPS) Backend Notes — Apple
Relevant to debugging memory ballooning issues encountered during generation.