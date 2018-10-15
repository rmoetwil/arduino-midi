/**
 * This program is based on the concepts of the MIDI Controller program from Notes ans Volts
 * See: http://www.notesandvolts.com/2016/07/arduino-midi-controller-multiplexers.html
 * 
 * This program uses a multiplexer to read 8 buttons.
 * When pressed or released it will send a midi signal.
 * 
 */
  
#include <Bounce2.h>
#include <MIDI.h>

// Multiplexter Pin configuration
int z = 7;
int s0 = 3;
int s1 = 4;
int s2 = 5;
int debounceTime = 5;
int muxChannelSelectStabelizeDelay = 50;

// Buttons
Bounce *buttons = new Bounce[8];
// Create MIDI class
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
    Serial.begin(9600);
    MIDI.begin(MIDI_CHANNEL_OFF);

    setUpButtons();
    setUpMultiplexer();
}

void loop() {
    updateMultiplexedButtons();
}

void setUpButtons() {
    for (int i = 0; i <= 7; i++) {
        buttons[i].attach(z, INPUT_PULLUP);
        buttons[i].interval(debounceTime);
    }
}

void setUpMultiplexer(){
    pinMode(s0, OUTPUT);
    pinMode(s1, OUTPUT);
    pinMode(s2, OUTPUT);
}

void updateMultiplexedButtons() {
    for (int i = 0; i <= 7; i++) {
        // select the bit
        int r0 = bitRead(i, 0);
        int r1 = bitRead(i, 1);
        int r2 = bitRead(i, 2);

        digitalWrite(s0, r0);
        digitalWrite(s1, r1);
        digitalWrite(s2, r2);

       // delayMicroseconds(muxChannelSelectStabelizeDelay);

        //Update Button
        buttons[i].update();
        if (buttons[i].rose()){ 
            //Serial.println(String("Button ") + (i + 1) + " up");
            MIDI.sendNoteOff(36 + i, 127, 1);
        }

        if (buttons[i].fell()) {
           //Serial.println(String("Button ") + (i + 1) + " down");
           MIDI.sendNoteOn(36 + i, 127, 1);
        }
   }
}