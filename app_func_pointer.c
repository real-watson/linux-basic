#include <stdio.h>

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

int calculate(int x, int y)
{
	int (*p) (int a, int b);
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
