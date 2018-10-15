 # Arduino 8 Button MIDI Controller 
 
 This program is based on the concepts of the MIDI Controller program from Notes ans Volts
 
See: http://www.notesandvolts.com/2016/07/arduino-midi-controller-multiplexers.html

I've (re)written the program so it is more compatible with other Arduino boards and made use of the popular Bounce library.

This program uses a multiplexer to read 8 buttons.

When pressed or released it will send a midi signal.
 
Multiplexer used:
- CD74HCT4051E (8 channel)

Arduino used:
- Arduino nano.
- Teensy 3.2 with Audio shield.

## Dependencies
This project depends on the following libraries
- Bounce2 by Thomas O Fredericks
- MIDI by Francois Best

See platformio.ini file for details.

## Notes
While the code will probably work in an Arduino IDE I used PlatformIO IDE with Visual Studio Code.

## TODO
- Make MIDI notes configurable.
- Maybe extend Bounce class.
- Build & deploy for Teensy 3.2 (with Audio shield mounted).
- If possible, use MIDI via TX and Serial.println via USB.
