// #include <Arduino.h>
#include <avr/io.h>
#include <util/delay.h>


int main(void){
  // inits
  DDRB |= (1 << PB0);

  // event loop
  while (1){
    PORTB = 0b00000010; // turn on the first led pin on portB
    _delay_ms(500);

    PORTB = 0b00000000; // turn off all leds
    _delay_ms(500);


  }

  return 0;
  

}