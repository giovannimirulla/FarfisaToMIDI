#include "MIDIUSB.h"
#include <Keypad.h>

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}

const byte ROWS = 6;
const byte COLS = 8; 

byte keys[ROWS][COLS] = {
{33, 33, 41, 49, 57, 65, 64, 34},
{42, 50, 58, 66, 53, 35, 43, 51},
{59, 67, 42, 36, 44, 52, 60, 68},
{57, 37, 45, 53, 61, 69, 63, 38},
{46, 54, 62, 70, 69, 39, 47, 55},
{63, 71, 75, 40, 48, 56, 64, 72}
};
byte rowPins[ROWS] = {A1, A2, A3, A4, A5, A6};
byte colPins[COLS] = {7, 8, 9, 10, 11, 12, 13, 14}; // Adjusted to have 8 columns

byte Channel = 0;
byte velocity = 80;

Keypad kpd = Keypad(makeKeymap(keys),colPins , rowPins, COLS, ROWS);

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (kpd.getKeys()) {
    for (int i = 0; i < LIST_MAX; i++) {
      if (kpd.key[i].stateChanged) {
        switch (kpd.key[i].kstate) {
          case PRESSED:
            Serial.print(int(kpd.key[i].kchar));
            Serial.print(", ");
            noteOn(Channel, uint8_t(kpd.key[i].kchar), velocity);
            MidiUSB.flush();
            break;
          case RELEASED:
            noteOff(Channel, uint8_t(kpd.key[i].kchar), velocity);
            MidiUSB.flush();
            break;
        }
      }
    }
  }
}
