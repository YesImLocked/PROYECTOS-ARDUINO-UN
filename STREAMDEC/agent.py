import os
from typing import Optional

_pipeline = None

def _init_pipeline():
    global _pipeline
    if _pipeline is not None:
        return
    model_name = os.getenv('STREAMDEC_MODEL', 'gpt2')
    try:
        from transformers import pipeline
        _pipeline = pipeline('text-generation', model=model_name, device=-1)
    except Exception as e:
        raise RuntimeError(f"No se pudo inicializar el modelo '{model_name}': {e}")


def generate(prompt: str, max_length: int = 200) -> str:
    """Genera texto localmente usando `transformers`.

    - Configuración del modelo mediante la variable de entorno `STREAMDEC_MODEL`.
    - Por defecto usa `gpt2` (ligero, funciona en CPU).
    """
    _init_pipeline()
    outputs = _pipeline(prompt, max_length=max_length, do_sample=True, top_p=0.95, top_k=50, num_return_sequences=1)
    text = outputs[0].get('generated_text')
    return text


if __name__ == '__main__':
    import argparse

    parser = argparse.ArgumentParser(description='Agent local para STREAMDEC')
    parser.add_argument('prompt', nargs='+', help='Texto de entrada para el agente')
    parser.add_argument('--max-length', type=int, default=200)
    args = parser.parse_args()
    prompt = ' '.join(args.prompt)
    try:
        out = generate(prompt, max_length=args.max_length)
        print(out)
    except Exception as e:
        print(f'Error: {e}')
