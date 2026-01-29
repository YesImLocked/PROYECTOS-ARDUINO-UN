#include <Servo.h>

Servo torreta;

// --- PINES ---
const int pinMira = A0;     // Joystick X (Mover la torreta)
const int pinBoton = 2;     // EL NUEVO CABLE: SW al Pin 2
const int pinServo = 9;
const int pinBuzzer = 10;

// --- VARIABLES ---
int posicionEnemigo;        
int anguloActual;           
unsigned long ultimoBip = 0;
bool objetivoBloqueado = false;

// Variables del enemigo escurridizo
unsigned long tiempoUltimoMovimiento = 0;
const int tiempoPaciencia = 5000; // 5 segundos antes de que se mueva

void setup() {
  torreta.attach(pinServo);
  pinMode(pinBuzzer, OUTPUT);
  
  // ACTIVAMOS LA RESISTENCIA INTERNA PARA EL BOTÓN
  // Esto es clave: hace que no necesites resistencias externas.
  pinMode(pinBoton, INPUT_PULLUP); 
  
  randomSeed(analogRead(A5)); 
  respawnEnemigo(); 
}

void loop() {
  // 1. MOVER (Igual que antes)
  int lecturaX = analogRead(pinMira);
  anguloActual = map(lecturaX, 0, 1023, 0, 180);
  torreta.write(anguloActual);

  // 2. RADAR Y MOVIMIENTO AUTOMÁTICO
  if (millis() - tiempoUltimoMovimiento > tiempoPaciencia) {
    cambioDePosicionAutomatico();
  }

  int distancia = abs(anguloActual - posicionEnemigo);
  
  if (distancia < 5) { // EN LA MIRA
    objetivoBloqueado = true;
    tone(pinBuzzer, 2000); 
  } 
  else if (distancia < 40) { // CERCA
    objetivoBloqueado = false;
    int velocidadBip = map(distancia, 5, 40, 40, 300);
    sonarRadar(velocidadBip);
  } 
  else { // LEJOS
    objetivoBloqueado = false;
    noTone(pinBuzzer);
  }

  // 3. DISPARAR (AHORA CON EL BOTÓN)
  // Al usar INPUT_PULLUP, el botón da LOW cuando lo apretás.
  if (digitalRead(pinBoton) == LOW) { 
    disparar();
    delay(300); // Anti-rebote para que no dispare doble
  }
  
  delay(15);
}

void sonarRadar(int intervalo) {
  if (millis() - ultimoBip > intervalo) {
    tone(pinBuzzer, 800, 30); 
    ultimoBip = millis();
  }
}

void disparar() {
  if (objetivoBloqueado) {
    // --- ¡IMPACTO! ---
    tone(pinBuzzer, 100, 50); 
    delay(50);
    for (int i=0; i<5; i++) { 
       tone(pinBuzzer, random(100, 600), 30);
       delay(30);
    }
    
    // Recoil
    int retroceso = (anguloActual > 90) ? -25 : 25; 
    torreta.write(anguloActual + retroceso);
    delay(100);
    torreta.write(anguloActual); 
    
    delay(500); 
    respawnEnemigo();
    
  } else {
    // --- ERRASTE ---
    tone(pinBuzzer, 150, 150); 
    torreta.write(anguloActual - 5);
    delay(50);
    torreta.write(anguloActual);
  }
}

void respawnEnemigo() {
  posicionEnemigo = random(20, 160);
  tiempoUltimoMovimiento = millis();
  tone(pinBuzzer, 1500, 100);
  delay(100);
  tone(pinBuzzer, 1500, 100);
}

void cambioDePosicionAutomatico() {
  posicionEnemigo = random(20, 160);
  tiempoUltimoMovimiento = millis();
  tone(pinBuzzer, 500, 50); 
}