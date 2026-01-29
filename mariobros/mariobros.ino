/*
 * Super Mario Bros Theme - Arduino
 * LCD 16x2 + Passive Buzzer
 *
 * Conexiones:
 * LCD (Paralelo):
 *   - RS  -> Pin 12
 *   - E   -> Pin 11
 *   - D4  -> Pin 5
 *   - D5  -> Pin 4
 *   - D6  -> Pin 3
 *   - D7  -> Pin 2
 *   - VSS -> GND
 *   - VDD -> 5V
 *   - V0  -> Potenciómetro 10K (contraste)
 *   - RW  -> GND
 *   - A   -> 5V (con resistencia 220Ω)
 *   - K   -> GND
 *
 * Buzzer Pasivo:
 *   - Pin Positivo -> Pin 8
 *   - Pin Negativo -> GND
 */

#include <LiquidCrystal.h>

// Inicializar LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Pin del buzzer
const int buzzerPin = 8;

// Definición de notas musicales (frecuencias en Hz)
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_REST 0

// Melodía de Super Mario Bros (Tema principal extendido)
int melody[] = {
  // Intro principal
  NOTE_E5, NOTE_E5, NOTE_REST, NOTE_E5,
  NOTE_REST, NOTE_C5, NOTE_E5, NOTE_REST,
  NOTE_G5, NOTE_REST, NOTE_REST, NOTE_REST,
  NOTE_G4, NOTE_REST, NOTE_REST, NOTE_REST,

  NOTE_C5, NOTE_REST, NOTE_REST, NOTE_G4,
  NOTE_REST, NOTE_REST, NOTE_E4, NOTE_REST,
  NOTE_REST, NOTE_A4, NOTE_REST, NOTE_B4,
  NOTE_REST, NOTE_AS4, NOTE_A4, NOTE_REST,

  NOTE_G4, NOTE_E5, NOTE_G5,
  NOTE_A5, NOTE_REST, NOTE_F5, NOTE_G5,
  NOTE_REST, NOTE_E5, NOTE_REST, NOTE_C5,
  NOTE_D5, NOTE_B4, NOTE_REST, NOTE_REST,

  // Segunda parte
  NOTE_C5, NOTE_REST, NOTE_REST, NOTE_G4,
  NOTE_REST, NOTE_REST, NOTE_E4, NOTE_REST,
  NOTE_REST, NOTE_A4, NOTE_REST, NOTE_B4,
  NOTE_REST, NOTE_AS4, NOTE_A4, NOTE_REST,

  NOTE_G4, NOTE_E5, NOTE_G5,
  NOTE_A5, NOTE_REST, NOTE_F5, NOTE_G5,
  NOTE_REST, NOTE_E5, NOTE_REST, NOTE_C5,
  NOTE_D5, NOTE_B4, NOTE_REST, NOTE_REST,

  // Sección melódica
  NOTE_REST, NOTE_REST, NOTE_G5, NOTE_FS5,
  NOTE_F5, NOTE_DS5, NOTE_REST, NOTE_E5,
  NOTE_REST, NOTE_GS4, NOTE_A4, NOTE_C5,
  NOTE_REST, NOTE_A4, NOTE_C5, NOTE_D5,

  NOTE_REST, NOTE_REST, NOTE_G5, NOTE_FS5,
  NOTE_F5, NOTE_DS5, NOTE_REST, NOTE_E5,
  NOTE_REST, NOTE_C5, NOTE_REST, NOTE_C5,
  NOTE_C5, NOTE_REST, NOTE_REST, NOTE_REST,

  // Repetición intro
  NOTE_E5, NOTE_E5, NOTE_REST, NOTE_E5,
  NOTE_REST, NOTE_C5, NOTE_E5, NOTE_REST,
  NOTE_G5, NOTE_REST, NOTE_REST, NOTE_REST,
  NOTE_G4, NOTE_REST, NOTE_REST, NOTE_REST,

  NOTE_C5, NOTE_REST, NOTE_REST, NOTE_G4,
  NOTE_REST, NOTE_REST, NOTE_E4, NOTE_REST,
  NOTE_REST, NOTE_A4, NOTE_REST, NOTE_B4,
  NOTE_REST, NOTE_AS4, NOTE_A4, NOTE_REST,

  NOTE_G4, NOTE_E5, NOTE_G5,
  NOTE_A5, NOTE_REST, NOTE_F5, NOTE_G5,
  NOTE_REST, NOTE_E5, NOTE_REST, NOTE_C5,
  NOTE_D5, NOTE_B4, NOTE_REST, NOTE_REST
};

// Duraciones (8 = corchea, 4 = negra, 2 = blanca, 1 = redonda, 6 = corchea con puntillo)
int noteDurations[] = {
  // Intro principal
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,

  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,

  6, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,

  // Segunda parte
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,

  6, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,

  // Sección melódica
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,

  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,

  // Repetición intro
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,

  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,

  6, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8
};

int melodySize = sizeof(melody) / sizeof(melody[0]);

// Melodía 2: Super Mario Bros Underground Theme
int melody2[] = {
  NOTE_C4, NOTE_C5, NOTE_A4, NOTE_A5,
  NOTE_AS4, NOTE_AS5, NOTE_REST,
  NOTE_REST,

  NOTE_C4, NOTE_C5, NOTE_A4, NOTE_A5,
  NOTE_AS4, NOTE_AS5, NOTE_REST,
  NOTE_REST,

  NOTE_F4, NOTE_F5, NOTE_D4, NOTE_D5,
  NOTE_DS4, NOTE_DS5, NOTE_REST,
  NOTE_REST,

  NOTE_F4, NOTE_F5, NOTE_D4, NOTE_D5,
  NOTE_DS4, NOTE_DS5, NOTE_REST,
  NOTE_REST,

  NOTE_DS5, NOTE_CS5, NOTE_D5,
  NOTE_CS5, NOTE_DS5,
  NOTE_DS5, NOTE_GS4,
  NOTE_G4, NOTE_CS5,

  NOTE_C5, NOTE_FS4, NOTE_F4, NOTE_E4,
  NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B4,
  NOTE_AS4, NOTE_A4, NOTE_GS4,

  NOTE_REST, NOTE_REST, NOTE_REST
};

int noteDurations2[] = {
  8, 8, 8, 8,
  8, 8, 8,
  8,

  8, 8, 8, 8,
  8, 8, 8,
  8,

  8, 8, 8, 8,
  8, 8, 8,
  8,

  8, 8, 8, 8,
  8, 8, 8,
  8,

  6, 6, 6,
  6, 6,
  6, 8,
  8, 6,

  6, 8, 8, 8,
  6, 8,
  6, 8, 8,
  8, 8, 8,

  2, 2, 2
};

int melody2Size = sizeof(melody2) / sizeof(melody2[0]);

// Variables para el scroll
String scrollText = "   Arduino rocks!!   ";
int scrollPos = 0;
unsigned long lastScrollTime = 0;
const int scrollDelay = 300; // Velocidad del scroll en milisegundos

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);

  // Mensaje de inicio
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Estas");
  lcd.setCursor(0, 1);
  lcd.print("escuchando");
  delay(1500);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  Mario Bros!!");
  delay(1000);
}

// Función para actualizar el scroll
void updateScroll() {
  if (millis() - lastScrollTime >= scrollDelay) {
    lcd.setCursor(0, 0);

    // Mostrar 16 caracteres desde la posición actual
    String displayText = "";
    for (int i = 0; i < 16; i++) {
      displayText += scrollText.charAt((scrollPos + i) % scrollText.length());
    }
    lcd.print(displayText);

    // Avanzar posición
    scrollPos++;
    if (scrollPos >= scrollText.length()) {
      scrollPos = 0;
    }

    lastScrollTime = millis();
  }
}

// Función para reproducir una melodía
void playMelody(int* notes, int* durations, int size, String message) {
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(message);

  for (int thisNote = 0; thisNote < size; thisNote++) {
    int noteDuration = 1000 / durations[thisNote];

    if (notes[thisNote] != NOTE_REST) {
      tone(buzzerPin, notes[thisNote], noteDuration * 0.9);
    }

    unsigned long noteStartTime = millis();
    int pauseBetweenNotes = noteDuration * 1.30;

    while (millis() - noteStartTime < pauseBetweenNotes) {
      updateScroll();
    }

    noTone(buzzerPin);
  }

  // Pausa después de la melodía
  unsigned long pauseStart = millis();
  while (millis() - pauseStart < 2000) {
    updateScroll();
  }
}

void loop() {
  // Reproducir primera melodía (Main Theme)
  playMelody(melody, noteDurations, melodySize, " Main Theme!");

  // Reproducir segunda melodía (Underground)
  playMelody(melody2, noteDurations2, melody2Size, " Underground!");
}
