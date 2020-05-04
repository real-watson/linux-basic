#include <stdio.h>
#include <stdlib.h>

void get_memory(char **p, int n)
{
	/*
	 * **p from &string
	 * get the address of string as *p*/
	*p = (char *)malloc(sizeof(char) * n);
}


