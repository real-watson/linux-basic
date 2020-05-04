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

void res_get_memory()
{
	char *p = NULL;
	char str[64] = "helloworld";
	int n = 100;

	p = (char *)malloc(sizeof(char) * n);
	if (NULL == p){
		return;
	}
	//strcpy(p,str);
	memcpy(p,str,strlen(str));
	printf("The str is %s\n",p);
}


