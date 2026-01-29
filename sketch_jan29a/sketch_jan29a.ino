const int pinX = A0;
const int pinY = A1;
const int pinClick = 2;

void setup() {
  Serial.begin(115200); // <--- ACÁ ESTÁ EL CAMBIO (Velocidad x12)
  pinMode(pinClick, INPUT_PULLUP);
}

void loop() {
  Serial.print(analogRead(pinX));
  Serial.print(",");
  Serial.print(analogRead(pinY));
  Serial.print(",");
  Serial.println(digitalRead(pinClick));

  delay(5); // <--- ESPERA MENOS (Antes era 20)
}