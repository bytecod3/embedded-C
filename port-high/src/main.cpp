#include <Arduino.h>

// default address for atmega328p DDRB
unsigned char *portDDRC;
unsigned char *portDDRB;
unsigned char *portC;

void setup() {
  // put your setup code here, to run once:
  
  portDDRC = 0x27; // assign the addresses
  portC = 0x28;

  *portDDRC |= 0x00; // set portB as output
  *portC |= 0x01; // write bit 0 as 0
  
}

void loop() {
  // put your main code here, to run repeatedly:
}
