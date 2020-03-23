#include <stdio.h>
#define VERSION "v2.1rc1"
typedef unsigned int uint32;
/*0x12345678 -> 0x78563412 as well as LE_TO_BE(le)*/
#define BE_TO_LE(be) ( \
					 (((uint32)(be) & 0xff000000) >> 24) |\
					 (((uint32)(be) & 0x00ff0000) >> 8)  |\
					 (((uint32)(be) & 0x0000ff00) << 8)  |\
					 (((uint32)(be) & 0x000000ff) << 24)  \
					 )
/*0x12345678 -> 0x5678 1234 reverse*/
#define BASE_BE_TO_LE(be) ( \
					(((uint32)(be) & 0xffff0000) >> 16) |\
					(((uint32)(be) & 0x0000ffff) << 16) \
					) 
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

/*
*name check_odd parity 
*input param: binary data
*input param: length
*return: 0 means not failed
*/

int check_odd_parity(int array[], unsigned int len)
{
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
	float n; 
	int total_n = 0;
	int i = 0;
	m = (int)num;
	n = num - m;
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
		if (n == 1)
			break;
	}
	*/
	printf("The output is %d\n",total_m);
	
}

int main(int argc, char **argv)
{
	int xp = 0x12345678;
	int odd[10] = {0,1,1,0,1,0,0,0,1,1};  /*odd parity*/
	int res;
	unsigned int oddlen;
	float num = 100.125;
	printf("The latest version is %s\n",VERSION);
	res = query_endian_mode(xp);
	if (!res)
		printf("It is LE mode\n");
	oddlen = sizeof(odd)/sizeof(odd[0]);
	res = check_odd_parity(odd,oddlen);
	if (!res)
		printf("It suits odd parity\n");
	else
		printf("It does not suit\n");
	printf("The endian from the big to the little [%x]\n",BE_TO_LE(xp));
	standard_convert(num);
	return 0;
}
