#include <stdio.h>

/*
*name:query mode from system
*input param: null
*return: 0 means little endian or big endian
*/

int query_endian_mode(int check)
{
	char *ptr = (char*)&check;
	//printf("The res is %x at %p\n",*ptr,&ptr);
	if (*ptr == 0x78)//LE mode
		return 0;
	else
		return 1;
}


