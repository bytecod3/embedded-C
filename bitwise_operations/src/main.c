#include <stdio.h>
#include <stdint.h>
#include "bin_print.h"

// bitmasks defines
#define BIT2_MASK	0b00000100

int main(){
	uint8_t PORTB_VAL = 0b11000011;
	
	PORTB_VAL |= BIT2_MASK;

	PRINT_BIN(PORTB_VAL);
	
	return 0;
} 
