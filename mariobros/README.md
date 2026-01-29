# 🎮 Super Mario Bros Theme - Arduino

Proyecto Arduino que reproduce el tema principal de Super Mario Bros usando un LCD 16x2 y un buzzer pasivo.

## ✨ Características

- 🎵 Melodía completa del tema de Super Mario Bros
- 📺 Display LCD 16x2 con texto animado en scroll
- 🔊 Reproducción de audio con buzzer pasivo
- 🎮 Implementación fiel a las notas originales del juego

## 🔧 Hardware Requerido

| Componente | Cantidad | Descripción |
|------------|----------|-------------|
| Arduino UNO | 1 | O cualquier placa compatible |
| LCD 16x2 | 1 | Display de cristal líquido |
| Buzzer Pasivo | 1 | Para reproducir las notas musicales |
| Potenciómetro | 1 | 10kΩ para ajustar contraste del LCD |
| Resistencia | 1 | 220Ω para backlight del LCD |
| Protoboard | 1 | Para las conexiones |
| Cables | Varios | Para las conexiones |

## 📋 Diagrama de Conexiones

### LCD 16x2 (Modo Paralelo)
| Pin LCD | Pin Arduino | Descripción |
|---------|-------------|-------------|
| RS | 12 | Register Select |
| E | 11 | Enable |
| D4 | 5 | Data 4 |
| D5 | 4 | Data 5 |
| D6 | 3 | Data 6 |
| D7 | 2 | Data 7 |
| VSS | GND | Tierra |
| VDD | 5V | Alimentación |
| V0 | Potenciómetro | Contraste (pin central del pot) |
| RW | GND | Read/Write (GND = Write) |
| A | 5V | Backlight + (con resistencia 220Ω) |
| K | GND | Backlight - |

### Buzzer Pasivo
| Pin Buzzer | Pin Arduino |
|------------|-------------|
| Positivo (+) | 8 |
| Negativo (-) | GND |

## 🚀 Instalación y Uso

### Requisitos de Software
1. **VS Code** con la extensión de Arduino instalada, O
2. **Arduino IDE** (versión 1.8.x o superior)

### Librerías Necesarias
- **LiquidCrystal** - Incluida por defecto en Arduino IDE

### Pasos de Instalación

1. **Clonar o descargar el proyecto**
2. **Configurar VS Code** (si usas VS Code):
   - Lee [SETUP.md](SETUP.md) para instrucciones detalladas
   - Ajusta el puerto COM en [.vscode/arduino.json](.vscode/arduino.json)

3. **Compilar y subir**:
   - **VS Code**: Ctrl+Alt+R para verificar, Ctrl+Alt+U para subir
   - **Arduino IDE**: Abrir [mariobros.ino](mariobros.ino) y hacer clic en Upload

## 📝 Estructura del Código

- [mariobros.ino](mariobros.ino) - Archivo principal del proyecto
  - Definición de notas musicales [mariobros.ino:33-56](mariobros.ino#L33-L56)
  - Melodía completa [mariobros.ino:59-113](mariobros.ino#L59-L113)
  - Duraciones de notas [mariobros.ino:116-170](mariobros.ino#L116-L170)
  - Función de scroll [mariobros.ino:199-218](mariobros.ino#L199-L218)
  - Loop principal [mariobros.ino:220-252](mariobros.ino#L220-L252)

## 🎵 Funcionamiento

1. Al iniciar, muestra mensajes de bienvenida en el LCD
2. Reproduce la melodía completa del tema de Mario Bros
3. Durante la reproducción, el texto "Uiipiiii Mario Bros Song" se desplaza en la pantalla LCD
4. La melodía se repite en bucle infinito

## 🛠️ Personalización

### Cambiar el Texto del Scroll
Modifica la variable en [mariobros.ino:175](mariobros.ino#L175):
```cpp
String scrollText = "   Tu texto aquí   ";
```

### Ajustar la Velocidad del Scroll
Modifica el delay en [mariobros.ino:178](mariobros.ino#L178):
```cpp
const int scrollDelay = 300; // en milisegundos
```

### Cambiar el Tempo de la Música
Ajusta el cálculo de duración en [mariobros.ino:229](mariobros.ino#L229):
```cpp
int noteDuration = 1000 / noteDurations[thisNote];
// Valores menores = más rápido, valores mayores = más lento
```

## 📚 Recursos Adicionales

- [Documentación LiquidCrystal](https://www.arduino.cc/en/Reference/LiquidCrystal)
- [Tutorial LCD 16x2](https://docs.arduino.cc/learn/electronics/lcd-displays)
- [Función tone() de Arduino](https://www.arduino.cc/reference/en/language/functions/advanced-io/tone/)

## 🔍 Resolución de Problemas

Ver [SETUP.md](SETUP.md) para guía completa de resolución de problemas.

### Problemas Comunes

**El LCD no muestra nada:**
- Verifica las conexiones
- Ajusta el potenciómetro para el contraste
- Verifica que el pin RW esté conectado a GND

**No se escucha nada:**
- Verifica que estés usando un buzzer PASIVO (no activo)
- Revisa la conexión del pin 8
- Verifica la polaridad del buzzer

**Error de compilación:**
- Asegúrate de que Arduino IDE esté instalado
- Verifica que la librería LiquidCrystal esté disponible

## 📄 Licencia

Este proyecto es de código abierto y está disponible para uso educativo.

## 👨‍💻 Autor

Proyecto creado para demostración de Arduino con LCD y buzzer.

---

**¡Disfruta del tema de Mario Bros en tu Arduino! 🍄**
