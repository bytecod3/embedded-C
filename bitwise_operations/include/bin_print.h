#include <stdio.h>
#include <stdint.h>

#define PRINT_BIN(val) for(int i = 7; i >= 0; i--) printf("%u%s", (val>>i)&1, i == 0?"\n":"")

