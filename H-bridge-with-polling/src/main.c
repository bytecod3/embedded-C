#include <Arduino.h>
#define LOWER_NIBBLE_MASK 0x0F

// using PORTB for output
char * PORTDDRB;
char * portB;
char * PinB;


// assign default addresses
PORTDDRB = 0x24;
portB    = 0x25;
pinB     = 0x23;

status signal_change = TRUE, no_signal_change = FALSE;
char previous_sample, current_sample;
char * p_current_sample;
p_current_sample = &current_sample;

// declare function prototypes
void my_delay(unsigned long seconds);// delay
uint8_t reverse_direction(char dir_flag);// reverse direction function

enum transistor_sequences{
  MOTOR_OFF     = 0x0C,
  AB_ON_FORWARD = 0x05,
  BC_ON_REVERSE = 0x0A
};

typedef enum{
  // boolean for signal change status
  FALSE,
  TRUE
} status;


// reverse direction variable. 
char ON = 1, OFF =  2;

void setup() {
  *PORTDDRB = 0x00; // clear all bits in PORTB
  *PORTDDRB |= 0x0F;  // set the lower nibble of PORTDDRB as output and bit5 as INPUT for switch polling

  *portB &= ~(LOWER_NIBBLE_MASK); // clear the lower nibble on PORTB so we are sure it is 0 for start

  
}

void loop() {
  reverse_direction(ON); // call reverse direction function with variable 1. Motor spins forward
  my_delay(2000); // wait for 2 seconds. Change this delay time as desired

  reverse_direction(OFF); // reverse spin
  my_delay(2000); 
}

// reverse direction function
// if argument is 1, turn motor ON
uint8_t reverse_direction(char dir_flag){
  if(dir_flag == 1){
    *portB |= AB_ON_FORWARD;  // set the lower nibble 0000 0101. Forward spin
  }else if(dir_flag == 2){
    *portB &= ~(1<<2); // clear bit 3
    *portB |= BC_ON_REVERSE; // reverse transistor sequence for reverse direction
  }else{
    exit(0); // invalid argument passed. Exit program
  }
}

void my_delay(unsigned long seconds){
  volatile unsigned long i;
  unsigned long end_time = 1000 * seconds;
  for(i=0; i<end_time; i++);
}