// Mapa directo: Pin Arduino = Pata Display
int buzzer = 13; 
int contador = 1;
unsigned long anterior = 0;

// Definimos qué pata hace cada cosa (según el esquema del 3461AS-1)
int pA=11, pB=7, pC=4, pD=2, pE=1, pF=10, pG=5; 
int d1=12, d2=9, d3=8, d4=6;

int segs[] = {pA, pB, pC, pD, pE, pF, pG};
int digs[] = {d1, d2, d3, d4};

byte numeros[10][7] = {
  {1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, {1,1,1,1,0,0,1}, {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1}, {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0}, {1,1,1,1,1,1,1}, {1,1,1,0,0,1,1}
};

void setup() {
  for(int i=0; i<7; i++) pinMode(segs[i], OUTPUT);
  for(int i=0; i<4; i++) {
    pinMode(digs[i], OUTPUT);
    digitalWrite(digs[i], HIGH); 
  }
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (millis() - anterior >= 1000) {
    anterior = millis();
    contador++;
    if (contador > 100) contador = 1;
    tone(buzzer, 1000, 50); 
  }

  // Lógica de dibujo (Unidades, Decenas, Centenas)
  formar(3, contador % 10);
  if (contador >= 10) formar(2, (contador / 10) % 10);
  if (contador >= 100) formar(1, (contador / 100) % 10);
}

void formar(int d, int n) {
  for(int i=0; i<4; i++) digitalWrite(digs[i], HIGH); 
  for(int i=0; i<7; i++) digitalWrite(segs[i], numeros[n][i]);
  digitalWrite(digs[d], LOW); 
  delay(2); 
}