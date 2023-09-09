#include <avr/pgmspace.h>

#define NOTE_G5   784
#define NOTE_GS5  831
#define NOTE_A5   880
#define NOTE_AS5  932
#define NOTE_B5   988
#define NOTE_C6   1047
#define NOTE_CS6  1109
#define NOTE_D6   1175
#define NOTE_DS6  1245
#define NOTE_E6   1319
#define NOTE_F6   1397
#define NOTE_FS6  1480
#define NOTE_G6   1568

// Use PROGMEM to store data in flash memory
// Use read functions to read data in flash memory
int sound[][2] = {
  {NOTE_G5,1},
  {NOTE_C6,1},
  {NOTE_E6,1},
  {NOTE_C6,1},
  {NOTE_D6,1},
  {NOTE_G6,1},
};

int tempo = 100;

void setup() {
  pinMode(3, INPUT_PULLUP);
  pinMode(4, OUTPUT);
}

void loop() {
  if (digitalRead(3) == LOW) {
    for (int i = 0; i < sizeof(sound) / sizeof(sound[0]); i++) {
      tone(4,sound[i][0],sound[i][1]*tempo);
      delay(sound[i][1]*tempo+50);
    }
  }
}
