#include <stdio.h>
#define VERSION "v0.1"

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

int main(int argc, char **argv)
{
	int xp = 0x12345678;
	int res;
	printf("The latest version is %s\n",VERSION);
	res = query_endian_mode(xp);
	if (!res)
		printf("It is LE mode\n");
	return 0;
}
