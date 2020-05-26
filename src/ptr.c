#include <stdio.h>
#include <stdlib.h>

int sum(int x, int y)
{
	return (x + y);
}
int delta(int x, int y)
{
	return (x - y);
}
int multiple(int x, int y)
{
	return (x * y);
}
int divide(int x, int y)
{
	if (!y)
		return 0;
	return (x / y);
}

void calculate(int x, int y)
{
	int (*p) (int,int);
	/*
	* 如同char *p = buff;类似，定义一个函数指针， 
	* &获取函数的地址，指针指向该地址
	* 实现功能
	*/
	p = &sum;	
	printf("The sum is %d\n",(*p)(x,y));

	p = &delta;
	printf("The delta is %d\n",(*p)(x,y));

	p = &multiple;
	printf("The multiple is %d\n",(*p)(x,y));

	p = &divide;
	printf("The divide is %d\n",(*p)(x,y));


}


int get_random_number(void)
{
	return rand();/*return int*/
}

/*
* name: callback function
* input: number array
* input: size of array
* input: pointer function for get random numbers
* output: void
*/
void random_number_callback(int *number, int size, int(*get_next_number)(void))
{
	while(size--){
		number[size] = get_next_number();
		printf("The num is %d %d\n",size,number[size]);
	}
}
