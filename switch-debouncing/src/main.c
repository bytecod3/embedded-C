#include <Arduino.h>
#define BIT0_MASK 0x01 // 0000 0001

// function prototypes
void m_delay(unsigned long seconds);
uint8_t debounce(unsigned char *, unsigned long seconds);

unsigned char * PORTDDRD;   // using PORTC BIT0
unsigned char * PORTDataD; 
unsigned char * pinD;

PORTDDRD = 0x2A;  // default addresses addresses
PORTDataD = 0x2B;
pinD = 0x29;

typedef enum { // boolean for signal change status
  FALSE,
  TRUE
} status;

status signal_change = TRUE, no_signal_change = FALSE;

unsigned long debounce_time = 20; // change this rate as needed (units -> milliseconds)
unsigned char previous_sample;
unsigned char current_sample;   // sampling variables
unsigned char * p_current_sample;
p_current_sample = &current_sample;


void setup() {
  *PORTDDRD = (*PORTDDRD) & (~BIT0_MASK); // make bit 0 an input
  *PORTDataD = (*PORTDataD) | (BIT0_MASK); // turn bit0 pull-up resistor ON
}

void loop() {
  *p_current_sample = (*pinD) & BIT0_MASK; 
  if(*p_current_sample != previous_sample){  // test bit0. (True only if both are true)
    if(debounce(p_current_sample, debounce_time) == TRUE){
      /*
      signal change has changed on pin. Do something!
      */
    } else{
      /*
      no signal change has occured.
      */
    }

  }

  previous_sample = *p_current_sample;  // update values

}

uint8_t debounce(unsigned char * currentValue, unsigned long time){
  uint8_t status = 0x00;

  // wait for the switch to bounce for -time- seconds
  m_delay(time);

  *p_current_sample = (*pinD) & BIT0_MASK; // re-sample pin after -time- 

  if (*p_current_sample != previous_sample){
    // if current_value after -time- is different from previous sample, a true signal-event has occured. Return 1
    return signal_change;
  } else{
    return no_signal_change;
  }

  previous_sample = *p_current_sample;
}

void m_delay(unsigned long seconds){
  volatile unsigned long i;
  unsigned long end_time = 1000 * seconds;
  for(i = 0; i < end_time; i++);

}