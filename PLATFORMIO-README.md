# 🚀 Guía de PlatformIO para Proyectos Arduino-UN

Esta guía te ayudará a usar PlatformIO para compilar y subir todos tus proyectos Arduino.

## 📦 ¿Qué es PlatformIO?

PlatformIO es una plataforma profesional de desarrollo para proyectos embebidos que ofrece:
- ✅ Gestión automática de librerías
- ✅ Compilación más rápida que Arduino IDE
- ✅ Soporte para múltiples placas y frameworks
- ✅ IntelliSense mejorado en VS Code
- ✅ Gestión de múltiples proyectos

## 🔧 Instalación

### Opción 1: Extensión de VS Code (Recomendado)

1. Abre VS Code
2. Ve a Extensions (Ctrl+Shift+X)
3. Busca "PlatformIO IDE"
4. Instala la extensión oficial

### Opción 2: CLI (Línea de comandos)

```bash
# Windows (PowerShell)
pip install platformio

# Verificar instalación
pio --version
```

## 📁 Estructura de Proyectos

```
PROYECTOS-ARDUINO-UN/
├── platformio.ini           # ← Configuración maestra (todos los proyectos)
├── mariobros/
│   ├── platformio.ini      # ← Configuración individual
│   └── mariobros.ino
├── sketch_jan28a/
│   ├── platformio.ini
│   └── sketch_jan28a.ino
├── sketch_jan28c/
│   ├── platformio.ini
│   └── sketch_jan28c.ino
├── sketch_jan29a/
│   ├── platformio.ini
│   └── sketch_jan29a.ino
└── STREAMDEC/
    ├── platformio.ini
    └── STREAMDEC.ino
```

## 🎯 Proyectos Disponibles

| Environment | Proyecto | Hardware |
|-------------|----------|----------|
| `mariobros` | Mario Bros Enhanced | LCD 16x2 + Buzzer |
| `led_button` | LED con Botón | LED + Botón |
| `servo_turret` | Juego de Torreta | Servo + Joystick + Buzzer |
| `joystick_serial` | Lectura Joystick | Joystick analógico |
| `mariobros_original` | Mario Bros Original | LCD 16x2 + Buzzer |

## 🚀 Uso

### Opción A: Usando VS Code con PlatformIO

#### 1. Abrir Proyecto Individual
```
1. File → Open Folder
2. Selecciona una carpeta de proyecto (ej: mariobros/)
3. PlatformIO detectará automáticamente el platformio.ini
4. Click en el ícono ✓ (Build) para compilar
5. Click en → (Upload) para subir al Arduino
```

#### 2. Trabajar con Todos los Proyectos
```
1. File → Open Folder
2. Selecciona PROYECTOS-ARDUINO-UN/
3. En la barra inferior, selecciona el environment
4. Click en ✓ para compilar el proyecto seleccionado
5. Click en → para subir
```

### Opción B: Usando CLI (Línea de comandos)

#### Compilar un proyecto específico
```bash
# Desde el directorio raíz
cd "C:\Users\Ferminashe\OneDrive\Desktop\PROYECTOS-ARDUINO-UN"

# Compilar mariobros
pio run -e mariobros

# Compilar torreta con servo
pio run -e servo_turret

# Compilar todos
pio run
```

#### Subir al Arduino
```bash
# Subir mariobros
pio run -e mariobros -t upload

# Subir y abrir monitor serial
pio run -e mariobros -t upload && pio device monitor -e mariobros
```

#### Monitor Serial
```bash
# Abrir monitor serial para mariobros (9600 baud)
pio device monitor -e mariobros

# Abrir monitor para joystick (115200 baud)
pio device monitor -e joystick_serial
```

#### Limpiar compilaciones
```bash
# Limpiar un proyecto
pio run -e mariobros -t clean

# Limpiar todos
pio run -t clean
```

## ⚙️ Configuración del Puerto COM

Todos los archivos `platformio.ini` están configurados con `COM3` por defecto.

**Para cambiar el puerto:**

### Método 1: Editar platformio.ini
```ini
upload_port = COM4      # Cambiar a tu puerto
monitor_port = COM4
```

### Método 2: Detectar automáticamente
```bash
# Listar puertos disponibles
pio device list

# PlatformIO detectará automáticamente si omites upload_port
```

### Método 3: Usar variable de entorno
```bash
# Windows PowerShell
$env:UPLOAD_PORT = "COM4"
pio run -e mariobros -t upload
```

## 📊 Comandos Útiles

```bash
# Ver información de la placa
pio boards uno

# Actualizar plataformas y librerías
pio update

# Buscar librerías
pio lib search LiquidCrystal

# Instalar librería
pio lib install "LiquidCrystal"

# Ver información del proyecto
pio project config

# Compilar en modo verbose
pio run -e mariobros -v

# Generar archivos de compilación para debug
pio debug
```

## 🎨 Atajos de Teclado en VS Code

Con PlatformIO instalado:

| Atajo | Acción |
|-------|--------|
| `Ctrl+Alt+B` | Build (Compilar) |
| `Ctrl+Alt+U` | Upload (Subir) |
| `Ctrl+Alt+S` | Serial Monitor |
| `Ctrl+Alt+T` | Run Task |

## 🔍 Resolución de Problemas

### Error: "Port COM3 not found"
```bash
# Listar puertos disponibles
pio device list

# Actualizar platformio.ini con el puerto correcto
```

### Error: "Platform 'atmelavr' not installed"
```bash
# Instalar plataforma
pio platform install atmelavr
```

### Error de compilación de librerías
```bash
# Limpiar y recompilar
pio run -t clean
pio lib update
pio run
```

### IntelliSense no funciona
```bash
# Regenerar archivos de configuración
pio init --ide vscode
```

## 📚 Recursos Adicionales

- [Documentación oficial de PlatformIO](https://docs.platformio.org/)
- [Guía de inicio rápido](https://docs.platformio.org/en/latest/integration/ide/vscode.html)
- [Referencia de platformio.ini](https://docs.platformio.org/page/projectconf.html)
- [Registro de plataformas](https://registry.platformio.org/platforms)

## 🆚 PlatformIO vs Arduino IDE

| Característica | PlatformIO | Arduino IDE |
|----------------|------------|-------------|
| Velocidad de compilación | ⚡ Muy rápida | 🐌 Lenta |
| Gestión de librerías | ✅ Automática | 🔧 Manual |
| Multi-proyecto | ✅ Sí | ❌ No |
| IntelliSense | ✅ Completo | 🟡 Básico |
| Debugging | ✅ Avanzado | ❌ Limitado |
| Curva de aprendizaje | 🟡 Media | ✅ Fácil |

## 💡 Consejos Pro

1. **Usa el workspace maestro** para cambiar rápidamente entre proyectos
2. **Configura alias** para comandos frecuentes
3. **Usa monitor_filters** para mejor visualización del serial
4. **Aprovecha el IntelliSense** para autocompletado
5. **Usa build_flags** para configuraciones específicas

## 🎯 Siguiente Paso

¡Ya estás listo! Prueba compilar tu primer proyecto:

```bash
cd "C:\Users\Ferminashe\OneDrive\Desktop\PROYECTOS-ARDUINO-UN"
pio run -e mariobros -t upload
pio device monitor -e mariobros
```

---

**¿Problemas o preguntas?** Consulta la [documentación oficial](https://docs.platformio.org/) o abre un issue en GitHub.
