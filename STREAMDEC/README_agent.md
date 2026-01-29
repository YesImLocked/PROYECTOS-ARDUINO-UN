# Agente IA local para STREAMDEC

Este README explica cómo instalar y usar el agente IA local integrado en `STREAMDEC`.

Requisitos:
- Python 3.8+
- `pip` y preferiblemente un entorno virtual

Instalación (recomendado):

```bash
python -m venv .venv
./.venv/Scripts/activate
pip install -r STREAMDEC/requirements.txt
```

Notas:
- Por defecto el agente usa el modelo `gpt2` (ligero) vía `transformers`.
- Para usar otro modelo local, exporta la variable `STREAMDEC_MODEL` con el identificador del modelo de Hugging Face (por ejemplo, `gpt2-medium` o un modelo descargado localmente).

Uso desde serial (Arduino):
- Envía por serial una línea con prefijo `AGENT:` seguida del prompt. Ejemplo enviado desde Arduino:

```
AGENT: Hola, ¿puedes resumir cómo funciona este sketch?
```

El script `STREAMDEC/macro.py` detecta líneas que comienzan con `AGENT:` y enviará el texto al agente local. La respuesta se imprimirá en la consola.

Ejecutar el agente desde línea de comandos:

```bash
python -m STREAMDEC.agent "Escribe un saludo breve"
```

Limitaciones:
- Ejecutar modelos grandes en CPU puede ser lento y consumir mucha RAM. Para uso serio, considera instalar PyTorch con soporte CUDA y usar un GPU o usar soluciones como llama.cpp (requiere integración adicional).
