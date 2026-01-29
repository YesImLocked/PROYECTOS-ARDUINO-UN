void setup() {
  pinMode(8, OUTPUT);           // El LED
  pinMode(2, INPUT_PULLUP);     // El Botón (Truco: activa resistencia interna)
}

void loop() {
  // Leemos el botón.
  // OJO: Con INPUT_PULLUP, funciona al revés:
  // LOW (0) significa que está PRESIONADO (conectado a tierra)
  // HIGH (1) significa que está SUELTO
  
  if (digitalRead(2) == LOW) {
    digitalWrite(8, HIGH); // Si apretás, PRENDE
  } else {
    digitalWrite(8, LOW);  // Si soltás, APAGA
  }
}