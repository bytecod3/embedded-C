#include <Arduino.h>

#define  BIT0_MASK 0x01 // 0000 0001
#define  BIT_CLEAR 0x00


enum digits{
  // this enum holds bits responsible for turning on the LEDs for displaying that specific digit
  ZERO  =  0x3F,
  ONE   =  0x18,
  TWO   =  0x6D,
  THREE =  0x67,
  FOUR  =  0x53,
  FIVE  =  0x76,
  SIX   =  0x7E,
  SEVEN =  0x23,
  EIGHT =  0x7F,
  NINE  =  0x77
};

void myDelay(unsigned long seconds);
void setDigit(unsigned int digit);

uint8_t * portDDRB =  0x24; // address to PORTB DDR
uint8_t * portB    =  0x25; // address to PORT B data register

uint8_t * portDDRC =  0x27; // to hold LED g because PB7 is used by the external crystal
uint8_t * portC    =  0x28;

void setup() {
  *portDDRC |= BIT0_MASK;

  *portDDRB |= 0xFF; // set all pins on DDRB as output
  *portB |= 0XFF; // write all pins port B HIGH


}

void setDigit(uint8_t digit){

  // clear previous bits and set the desired bit for that digit

  switch (digit){
    case 0:
      *portB |= ZERO;
      *portC &= ~(BIT0_MASK); // clear portC bit 0. (g)
      break;

    case 1:
      *portB = (unsigned char *) 0x00;
      *portB |= ONE;
      break;

    case 2:
      *portB = (unsigned char *) 0x00;
      *portB |= TWO;
      *portC |= BIT0_MASK;
      break;

    case 3:
      *portB =  0x00;
      *portB |= THREE;
      *portC |= BIT0_MASK;
      break;

    case 4:
      *portB = 0x00;
      *portB |= FOUR;
      *portC |= BIT0_MASK;
      break;

    case 5:
      *portB =  0x00;
      *portB |= FIVE;
      *portC |= BIT0_MASK;
      break;

    case 6:
      *portB =  0x00;
      *portB |= SIX;
      *portC |= BIT0_MASK;
      break;

    case 7:
      *portB =  0x00;
      *portB |= SEVEN;
      *portC &= ~(BIT0_MASK); // clear g
      break;

    case 8:
      *portB =  0x00;
      *portB |= EIGHT;
      *portC |= BIT0_MASK;
      break;

    case 9:
      *portB =  0x00;
      *portB |= NINE;
      *portC |= BIT0_MASK;
      break;
    }
}


void loop() {
  // put your main code here, to run repeatedly:
}

void myDelay(unsigned char seconds){
  for(;;;)
}