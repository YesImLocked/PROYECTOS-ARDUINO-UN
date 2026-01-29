# Configuración del Proyecto Mario Bros - Arduino

## Requisitos Previos

### 1. Extensión de Arduino para VS Code
Necesitas instalar la extensión oficial de Arduino para VS Code:
- Abre VS Code
- Ve a Extensions (Ctrl+Shift+X)
- Busca "Arduino" (por Microsoft)
- Instala la extensión

### 2. Arduino IDE
Asegúrate de tener Arduino IDE instalado en tu sistema:
- Descarga desde: https://www.arduino.cc/en/software
- Instala la versión más reciente

## Librerías Necesarias

### LiquidCrystal
Esta librería **YA VIENE INCLUIDA** con Arduino IDE, no necesitas instalarla.
- Se usa para controlar el LCD 16x2
- Es parte de las librerías estándar de Arduino

## Configuración de VS Code

Los archivos de configuración ya están creados en [.vscode/](.vscode/):

### [.vscode/arduino.json](.vscode/arduino.json)
Configura:
- **Board**: Arduino UNO (`arduino:avr:uno`)
- **Port**: COM3 (cámbialo al puerto correcto en tu PC)
- **Sketch**: mariobros.ino

**IMPORTANTE**: Necesitas cambiar el puerto COM al que corresponda en tu sistema.

Para verificar el puerto correcto:
1. Conecta tu Arduino
2. Abre Arduino IDE
3. Ve a Tools > Port
4. Anota el puerto COM que aparece
5. Actualiza el puerto en [.vscode/arduino.json](.vscode/arduino.json)

### [.vscode/c_cpp_properties.json](.vscode/c_cpp_properties.json)
Configura IntelliSense para Arduino.
Las rutas pueden necesitar ajuste según tu instalación de Arduino.

## Compilar y Subir el Proyecto

### Opción 1: Usando VS Code (Recomendado)
1. Abre la paleta de comandos (Ctrl+Shift+P)
2. Escribe y selecciona:
   - `Arduino: Verify` para compilar
   - `Arduino: Upload` para subir al Arduino

### Opción 2: Usando Atajos de Teclado
- **Ctrl+Alt+R**: Verificar/Compilar
- **Ctrl+Alt+U**: Subir al Arduino

### Opción 3: Usando Arduino IDE
1. Abre [mariobros.ino](mariobros.ino) en Arduino IDE
2. Selecciona tu placa: Tools > Board > Arduino UNO
3. Selecciona tu puerto: Tools > Port > COMx
4. Haz clic en el botón Upload (→)

## Hardware Necesario

- Arduino UNO (o compatible)
- LCD 16x2
- Buzzer pasivo
- Potenciómetro 10kΩ (para contraste del LCD)
- Resistencia 220Ω (para backlight del LCD)
- Cables de conexión

## Conexiones

Ver comentarios en [mariobros.ino:5-23](mariobros.ino#L5-L23) para el diagrama de conexiones completo.

## Resolución de Problemas

### Error: "Port COM3 not found"
- Verifica que el Arduino esté conectado
- Actualiza el puerto en [.vscode/arduino.json](.vscode/arduino.json)

### Error de Compilación
- Verifica que Arduino IDE esté instalado correctamente
- Cierra y vuelve a abrir VS Code
- Ejecuta: `Arduino: Rebuild IntelliSense Configuration`

### IntelliSense no funciona
- Ajusta las rutas en [.vscode/c_cpp_properties.json](.vscode/c_cpp_properties.json)
- Verifica la ubicación de tu instalación de Arduino
