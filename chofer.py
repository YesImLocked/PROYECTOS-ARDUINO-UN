import serial
import pyautogui
import time

# --- CONFIGURACIÓN ---
PUERTO = 'COM3'  # <--- CHEQUEÁ TU PUERTO
BAUDIOS = 115200 # <--- TIENE QUE COINCIDIR CON ARDUINO
VELOCIDAD = 25   # Subí esto si querés que vaya más rápido

# Quitamos el delay de seguridad de PyAutoGUI para que sea instantáneo
pyautogui.PAUSE = 0 

CENTRO = 512
ZONA_MUERTA = 20

try:
    ser = serial.Serial(PUERTO, BAUDIOS, timeout=0.01) # Timeout corto
    time.sleep(2)
    print("¡Mouse TURBO activado!")

    while True:
        # TRUCO ANTILAG:
        # Si el buffer se llena, leemos todo y nos quedamos solo con la ÚLTIMA línea.
        # Así el cursor reacciona a lo que hacés AHORA, no hace 2 segundos.
        if ser.in_waiting > 0:
            datos_raw = ser.read(ser.in_waiting).decode('utf-8', errors='ignore')
            lineas = datos_raw.split('\n')
            
            # Buscamos la última línea completa válida
            linea_valida = ""
            if len(lineas) >= 2:
                linea_valida = lineas[-2].strip()
            
            if linea_valida:
                try:
                    partes = linea_valida.split(',')
                    if len(partes) == 3:
                        x = int(partes[0])
                        y = int(partes[1])
                        click = int(partes[2])

                        # Calcular movimiento
                        diff_x = x - CENTRO
                        diff_y = y - CENTRO
                        
                        mov_x = 0
                        mov_y = 0

                        if abs(diff_x) > ZONA_MUERTA:
                            mov_x = (diff_x / 512) * VELOCIDAD
                        
                        if abs(diff_y) > ZONA_MUERTA:
                            mov_y = (diff_y / 512) * VELOCIDAD

                        # Movemos solo si hace falta
                        if mov_x != 0 or mov_y != 0:
                            # moveRel es más rápido que move
                            pyautogui.moveRel(mov_x, mov_y) 

                        # Click
                        if click == 0:
                            pyautogui.click()
                            # Pequeña espera solo al clickear para no hacer doble click sin querer
                            while ser.in_waiting: ser.read() # Limpiamos buffer
                            time.sleep(0.15) 

                except ValueError:
                    pass

except Exception as e:
    print(f"Error: {e}")