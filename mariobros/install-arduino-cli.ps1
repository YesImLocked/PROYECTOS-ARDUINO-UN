# Script para instalar Arduino CLI en Windows
# Ejecutar como: powershell -ExecutionPolicy Bypass -File install-arduino-cli.ps1

Write-Host "Descargando Arduino CLI..." -ForegroundColor Green

$url = "https://downloads.arduino.cc/arduino-cli/arduino-cli_latest_Windows_64bit.zip"
$output = "$env:TEMP\arduino-cli.zip"
$installPath = "$env:LOCALAPPDATA\Arduino15"

# Crear directorio si no existe
New-Item -ItemType Directory -Force -Path $installPath | Out-Null

# Descargar
Invoke-WebRequest -Uri $url -OutFile $output

# Extraer
Expand-Archive -Path $output -DestinationPath $installPath -Force

# Agregar al PATH del usuario
$userPath = [Environment]::GetEnvironmentVariable("Path", "User")
if ($userPath -notlike "*$installPath*") {
    [Environment]::SetEnvironmentVariable("Path", "$userPath;$installPath", "User")
    Write-Host "Arduino CLI agregado al PATH" -ForegroundColor Green
}

# Configurar Arduino CLI
& "$installPath\arduino-cli.exe" core update-index
& "$installPath\arduino-cli.exe" core install arduino:avr

Write-Host "`nArduino CLI instalado exitosamente!" -ForegroundColor Green
Write-Host "Reinicia la terminal para usar 'arduino-cli'" -ForegroundColor Yellow

# Limpiar
Remove-Item $output
