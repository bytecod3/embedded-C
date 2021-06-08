#include <avr/io.h>
#include <util/delay.h>

#define DELAY_TIME 20

void pov_display(uint8_t one_byte){
  // a function to animate the LEDs
  PORTB = one_byte;

  _delay_ms(2);

}

int main(){

  uint8_t i = 0;

  DDRB = 0xFF; // set all the pins on DDRB to output

  while (1){ // event loop

    pov_display(0b00001001); // just some random combos!
    pov_display(0b11110000);
    pov_display(0b10101010);
    pov_display(0b01010101);
    pov_display(0b00001001);
    pov_display(0b11001100);
    pov_display(0b11100011);
    pov_display(0b00110011);

    while (i < 7 ){
      /* code */
      pov_display()
    }
    

    PORTB = 0;
    _delay_ms(10); 
    
  }
  
  return 0;
}