// Definición de pines
int pinX = A0;
int pinY = A1;
int pinSW = 2;   // El botón del joystick
int buzzer = 8;
int led = 9;

void setup() {
  pinMode(pinSW, INPUT_PULLUP); // Activamos la resistencia interna para el botón
  pinMode(led, OUTPUT);
}

void loop() {
  int valorX = analogRead(pinX);
  int valorY = analogRead(pinY);
  bool botonPulsado = (digitalRead(pinSW) == LOW); // LOW significa presionado

  // Si no apretamos el botón, suena el sinte
  if (!botonPulsado) {
    int frecuencia = map(valorX, 0, 1023, 100, 2000);
    int duracion = map(valorY, 0, 1023, 10, 150);
    
    tone(buzzer, frecuencia, duracion);
    analogWrite(led, map(valorX, 0, 1023, 0, 255)); // El LED brilla según el Pitch
    
    delay(duracion + 5);
  } else {
    // Si apretamos el botón, silencio total y LED apagado
    noTone(buzzer);
    digitalWrite(led, LOW);
  }
}