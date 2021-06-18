#include<avr/io.h>
#include<util/delay.h>

#define DELAY_TIME 20

void pov_display(uint8_t one_byte){
  // function to animate the LEDs
  PORTB = one_byte;

  _delay_ms(2);
}

int main(){
  uint8_t i = 0;
  
}