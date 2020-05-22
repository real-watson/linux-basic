#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*memory div*/

void memory_divide()
{
	static int sta_one = 0;
	static int sta_two = 0;
	int int_one = 0;
	int int_two = 0;

	/*check their address in memory*/
	printf(" sta_one[0x%p]\n sta_two[0x%p]\n int_one[0x%p]\n int_two[0x%p]\n",&sta_one,&sta_two,&int_one,&int_two);
	printf("The delta from sta to int is 0x%ld\n",&sta_one - &int_one);
}

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
			//flag = (sizeof(ptr = (char*)malloc(0)));/*sizeof is not zero*/
			//fix me warnings
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

