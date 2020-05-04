#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
*name check_odd parity 
*input param: binary data
*input param: length
*return: 0 means not failed
*/

int check_odd_parity(int array[], unsigned int len) {
	unsigned int total = 0;
	unsigned int i = 0;
	int *ptr = array;  /*new ptr for array*/
	while(1)
	{
		total += *ptr++;
		++i;
		if (i == len)  /*i <= len - 1*/
			break;
	}
	if (total % 2)  /*count the number of 1*/
		return 0;
	else
		return 1;
} 
/*
*name: 745 standard convert
*input param: 10.1231 like this
*return: void
*/

void standard_convert(float num)
{
	/*100.125 -> 1100100.001*/
	int res;
	int k = 1;
	int total_m = 0;
	int m;
	m = (int)num;
	while(1)
	{
		res = m % 2;
		total_m += k * res;
		k *= 10;
		m *= 0.5;
		if (!m)
			break;
	}
	/*
   	while(1)
   	{
    	n *= 2;
       	res = n / 1;
       	i++;
       	if (n == 1){
       		break;
       	}
       	printf("The output is %d\n",total_m);
	}
	*/
}

/*count the bits of number*/
int count_bits(int n)
{
       int res = 0;
       /*
       while(n)
       {
               res++;
               n = n&(n-1);
       }
       */
       while(n)
       {
               if ((n % 2))
                       res++;
               n = n / 2;
       }
       return res;
}
