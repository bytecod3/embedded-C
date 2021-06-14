#include <stdio.h>
#include <stdint.h>
#include "bin_print.h"

// bitmasks defines
#define BIT2_MASK	0b00000100

int main(){
	uint8_t PORTB_VAL = 0b11000011;
	
	// setting bit2. Alt: PORTB_VAL |= (1<<2) .OR
	PORTB_VAL |= BIT2_MASK; 
	PRINT_BIN(PORTB_VAL);
	
	// toggle bit 2 keeping others same. XOR
	PORTB_VAL ^= (1<<2); 
	PRINT_BIN(PORTB_VAL);
	
	// toggle more than one bit. XOR
	PORTB_VAL ^= (1<<2) | (1<<4); // bit 2 and 4
	
	// clearing bits with AND
	PORTB_VAL &= ~(1<<2);	// clear bit 2
	
	// clearing more than two bits
	PORTB_VAL &= ~((1<<2)| (1<<3)); // clear bit 2 and 4
		
	
	return 0;
} 
