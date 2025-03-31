# ai_helper.py

import sys
from gpt4all import GPT4All

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 ai_helper.py \"your question here\"")
        sys.exit(1)

    prompt = " ".join(sys.argv[1:])
    print("🧠 Running local LLM...\n")

    # Load model (adjust name/path if needed)
    model = GPT4All("mistral-7b-openorca.Q4_0.gguf", model_path="./models")

    # Start a session and get the response
    with model.chat_session() as session:
        response = session.generate(prompt)

    print("\n💡 Response:\n")
    print(response.strip())

if __name__ == "__main__":
    main()
