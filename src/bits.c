#include <stdio.h>

/*set bit*/
void reset_nbit(int x, unsigned int index)
{
	/*
	 * x=8 0x09 - 0b 0000 1001
	 * 0000 1001 -> index -> 0000 0001
	*/

	int bit = 0x00;
	switch(index){
		case 0: break;
		case 1:	bit = 0x01; break;
		case 2:	bit = 0x02; break;
		case 3:	bit = 0x04; break;
		case 4:	bit = 0x08; break;
		case 5:	bit = 0x10; break;
		case 6:	bit = 0x20; break;
		case 7:	bit = 0x40; break;
		case 8:	bit = 0x80; break;
		default: break;
	}
	x &= bit;
	printf("The x is %d\n",x);
}
