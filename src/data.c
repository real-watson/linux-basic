#include "data.h"

/*using ptr to swap number*/
void self_swap_number(int *x, int *y)
{
	int t;
	t = *x;
	*x = *y; /*y to x*/
	*y = t; /*x to y*/
}
/*static using*/
void self_sum_number(int x)
{
	static int all = 0;
	printf("The all is %d\n",all);
	all += x;
}

void self_all_number()
{
	int i;
	for (i=0; i<5; i++){
		self_sum_number(i);
	}
}	

/*sizeof*/
int size_space_full()
{
	int **a[3][4];
	/*
	 * xxxx xxxx xxxx xxxx 
	 * xxxx xxxx xxxx xxxx * int(4 bytes)  == 48 bytes( But in some platform it is 96)
	 * xxxx xxxx xxxx xxxx
	 */
	printf("The size of a is %ld\n",sizeof(a));	
	return sizeof(a);
}


