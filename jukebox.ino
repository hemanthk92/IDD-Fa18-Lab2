/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"
#include <LiquidCrystal.h>

#define ENC_A 2 //these need to be digital input pins
#define ENC_B 3

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int melodies[2][20] = {
  {
  NOTE_C2, NOTE_F3, NOTE_C3, NOTE_A2,
  NOTE_C3, NOTE_F3, NOTE_C3,
  NOTE_C3, NOTE_F3, NOTE_C3, NOTE_F3,
  NOTE_AS3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_D3, NOTE_CS3,
  NOTE_C3, NOTE_F3, NOTE_C3},
  {NOTE_D3,NOTE_D3,NOTE_D3,NOTE_G3,NOTE_D4,NOTE_C4,NOTE_B3,NOTE_A3,NOTE_G4,NOTE_D4,
  NOTE_C4,NOTE_B3,NOTE_A3,NOTE_G4,NOTE_D4,NOTE_C4,NOTE_B3,NOTE_C4,NOTE_A3,0}
  };

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[2][20] = {
  {
  4,    4,    4,    4,
  4,    4,          2,
  4,    4,    4,    4,
  3,   8, 8, 8, 8, 8,
  4,    4,    4}, 
  { 10,10,10,2,2,10,10,10,2,4, 
  10,10,10,2,4,10,10,10,2,4}
  };



void setup() {
  // iterate over the notes of the melody:
  lcd.clear();
  lcd.begin(16, 2);
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
  Serial.begin (9600);
  Serial.print("Hello");
  lcd.print("Hello World\n");
  int tmpdata;
  int currentEncoderValue;
  int newEncoderValue;

  currentEncoderValue = read_encoder();
  
  while(true){
    for (int thisSong = 0; thisSong < 2; thisSong++){
      
      for (int thisNote = 0; thisNote < 20; thisNote++) {
    
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[thisSong][thisNote];
        tone(8, melodies[thisSong][thisNote], noteDuration);
    
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(8);
        //lcd.clear();
        //lcd.setCursor(0, 1);
        Serial.print(20-thisNote);
        Serial.print("\n");
        newEncoderValue = read_encoder();
        if (newEncoderValue != currentEncoderValue) {
          break;
          };
        currentEncoderValue = newEncoderValue;
        
      }
    delay(1000);
    }
  }
  
}

void loop() {
  // no need to repeat the melody.
}

int read_encoder()
{
  static int enc_states[] = {
    0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0  };
  static byte ABab = 0;
  ABab *= 4;                   //shift the old values over 2 bits
  ABab = ABab%16;      //keeps only bits 0-3
  ABab += 2*digitalRead(ENC_A)+digitalRead(ENC_B); //adds enc_a and enc_b values to bits 1 and 0
  return ( enc_states[ABab]);
 
 
}
