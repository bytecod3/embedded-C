#define BV(bit)			(1<<bit)
#define setBit(byte, bit)	(byte |= BV(bit))
#define clearBit(byte, bit)	(byte &= ~BV(bit))
#define togleBit(byte, bit)	(byte ^= BV(bit))

