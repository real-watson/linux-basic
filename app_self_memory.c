#include <stdio.h>
#include <stdlib.h>

void get_memory(char **p, int n)
{
	/*
	 * **p from &string * get the address of string as *p*/
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
	} //strcpy(p,str);
	memcpy(p,str,strlen(str));
	printf("The str is %s\n",p);
}

void get_memory_zero(unsigned short flag)
{
	char *ptr = NULL;
	switch(flag){
		case 0:
			ptr = (char*)malloc(flag);
			flag = 1;
			break;
		case 1: 
			flag = (sizeof(ptr = (char*)malloc(0)));/*sizeof is not zero*/
			break;
		case 2:
			flag = (strlen(ptr = (char*)malloc(0)));
			break;
		default:
			break;
	}

	if (NULL == ptr){
		free(ptr);
		printf("The ptr is NULL\n");
		return;
	}
	if (!flag){
		printf("flag is zero\n");
		return;
	}

	free(ptr);
}

