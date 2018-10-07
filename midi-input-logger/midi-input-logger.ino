/*
 * This program is written and tested with Teensy 3.2 + Audio Shield.
 * 
 * It reads midi and prints all output to the Serial Monitor.
 * 
 * Note: Not all handlers are implemented. Haven't found a way to monitor them via a MIDI controller.
 */

void setup() {
   // Initialising serial monitor
  Serial.begin(9600);

  // Adding handlers for all midi actions
  usbMIDI.setHandleNoteOff(myNoteOff);
  usbMIDI.setHandleNoteOn(myNoteOn);
  usbMIDI.setHandleAfterTouchPoly(myAfterTouchPoly);
  usbMIDI.setHandleControlChange(myControlChange);
  usbMIDI.setHandleProgramChange(myProgramChange);
  usbMIDI.setHandleAfterTouch(myAfterTouch);
  usbMIDI.setHandlePitchChange(myPitchChange);
  usbMIDI.setHandleSystemExclusive(mySystemExclusiveChunk);
  usbMIDI.setHandleTimeCodeQuarterFrame(myTimeCodeQuarterFrame);
  usbMIDI.setHandleSongPosition(mySongPosition);
  usbMIDI.setHandleSongSelect(mySongSelect);
  usbMIDI.setHandleTuneRequest(myTuneRequest);
  usbMIDI.setHandleClock(myClock);
  usbMIDI.setHandleStart(myStart);
  usbMIDI.setHandleContinue(myContinue);
  usbMIDI.setHandleStop(myStop);
  usbMIDI.setHandleActiveSensing(myActiveSensing);
  usbMIDI.setHandleSystemReset(mySystemReset);
  usbMIDI.setHandleRealTimeSystem(myRealTimeSystem);
}

void loop() {
  usbMIDI.read();
}

void myNoteOn(byte channel, byte note, byte velocity) {
  Serial.println(String("Note On    ") + channel + "-" + note + "-" + velocity);
}

void myNoteOff(byte channel, byte note, byte velocity) {
  Serial.println(String("Note Off   ") + channel + "-" + note + "-" + velocity);
}
  
void myAfterTouchPoly(byte channel, byte note, byte velocity) {
  
}
void myControlChange(byte channel, byte control, byte value) {
  Serial.println(String("Midi CC    ") + channel + "-" + control + "-" + value);
}

void myProgramChange(byte channel, byte program) {
  Serial.println(String("Program CC ") + channel + "-" + program);
}

void myAfterTouch(byte channel, byte pressure) {
  Serial.println(String("Aftertouch ") + channel + "-" + pressure); 
}

void myPitchChange(byte channel, int pitch) {
  Serial.println(String("Pitch CC   ") + channel + "-" + pitch);  
}

void mySystemExclusiveChunk(const byte *data, uint16_t length, bool last) {
  
}

void mySystemExclusive(byte *data, unsigned int length) {
  
}

void myTimeCodeQuarterFrame(byte data) {
  
}

void mySongPosition(uint16_t beats) {
  
}

void mySongSelect(byte songNumber) {
  
}

void myTuneRequest() {

}

void myClock() {
  Serial.println("Clock");     
}

void myStart() {
  Serial.println("Start");   
}

void myContinue() {
  Serial.println("Continue");     
}

void myStop() {
  Serial.println("Stop");     
}

void myActiveSensing() {
  
}

void mySystemReset() {
  
}

void myRealTimeSystem(byte realtimebyte) {
  
}
