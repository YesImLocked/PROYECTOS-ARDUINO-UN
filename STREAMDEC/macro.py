import serial
import pyautogui
import time
import os

# Intento de importar el agente local si está disponible
try:
    import STREAMDEC.agent as local_agent
except Exception:
    local_agent = None

# --- CONFIGURACIÓN ---
# Asegurate de que este sea el puerto correcto de tu Arduino
puerto_arduino = 'COM3' 
baudios = 9600

try:
    ser = serial.Serial(puerto_arduino, baudios)
    time.sleep(2) # Espera técnica para conectar
    print(f"Conectado a {puerto_arduino}. ¡Listo para asignar Hotkeys!")
    print("Botón 1 = F13 (Mute Discord)")
    print("Botón 2 = F14 (Escena OBS 1)")
    print("Botón 3 = F15 (Escena OBS 2)")

    while True:
        if ser.in_waiting > 0:
            # Leemos y limpiamos el mensaje del Arduino
            linea = ser.readline().decode('utf-8').strip()
            
            if linea == "ACCION_1":
                print(">> Disparando F13")
                pyautogui.press('f13') 
                
            elif linea == "ACCION_2":
                print(">> Disparando F14")
                pyautogui.press('f14')
                
            elif linea == "ACCION_3":
                print(">> Disparando F15")
                pyautogui.press('f15')

            # Mensajes dirigidos al agente local: "AGENT: tu pregunta aquí"
            elif linea.startswith("AGENT:"):
                prompt = linea.split(":", 1)[1].strip()
                if local_agent is None:
                    print("Agente local no instalado. Consulta STREAMDEC/README_agent.md para instalarlo.")
                else:
                    try:
                        print(f">> Enviando al agente: {prompt}")
                        respuesta = local_agent.generate(prompt)
                        print(">> Respuesta del agente:")
                        print(respuesta)
                    except Exception as e:
                        print(f"Error al ejecutar el agente: {e}")

except Exception as e:
    print(f"Error: {e}")
    print("Chequeá el puerto COM en el Administrador de Dispositivos.")