/**
 * Basic midi input is a program to test if your midi circuit is working.
 * 
 * It basically let's the onboard led (13) blink when a Midi Note on message is received.
 * 
 */
#include <MIDI.h>

// Arduino Board LED is on pin 13.
#define LED 13    

// Created and binds the MIDI interface to the default hardware Serial port.
MIDI_CREATE_DEFAULT_INSTANCE();

void setup() {
  // Set Arduino board pin 13 to output.
  pinMode(LED, OUTPUT);
  // Set the channel to listen on. MIDI_CHANNEL_OMNI means all channels.
  MIDI.begin(MIDI_CHANNEL_OMNI);
  
  // Set Callbacks for specific MIDI commands.
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);
}

void loop() {
  // Continuously read incoming messages.
  MIDI.read();
}

/**
 * When a Note On message comes in, turn on the LED.
 */
void handleNoteOn(byte channel, byte pitch, byte velocity) { 
  digitalWrite(LED,HIGH);
}

/**
 * When a Note Off message comes in, turn off the LED.
 */
void handleNoteOff(byte channel, byte pitch, byte velocity) { 
  digitalWrite(LED,LOW);
}
