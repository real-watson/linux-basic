#include <stdio.h>
#include <stdlib.h>

void get_memory(char **p, int n)
{
	/*
	 * **p from &string
	 * get the address of string as *p*/
	printf("The add is %p\n",*p);
	*p = (char *)malloc(sizeof(char) * n);
	if (NULL == *p){
		return;
	}
}

char *res_get_memoery(char *p, int n)
{
	printf("The add is %p\n",*p);
	p = (char *)malloc(sizeof(char) * n);
	if (NULL == p){
		return NULL;
	}
	return p;
}


