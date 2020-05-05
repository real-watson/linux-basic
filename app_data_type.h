#ifndef _APP_DATA_TYPE_

#include <stdio.h>
#include <stdlib.h>

/*union type*/
#define SIZEOFUNION sizeof(union union_type \
				{ \
				unsigned int age; \
				int id; \
				char name[64]; \
				})

/*struct type*/
#define SIZEOFSTRUCT sizeof(struct struct_type \
				{ \
				unsigned int age; \
				int id; \
				char name[64]; \
				})

typedef struct clothes{
		int size;
		int price;
}INFO;

/*two structs
 * int int char64 (struct)
 * int int char int int 
 * 4 4 64 4 4 
 * 4+4+4+4+64 = 80
 * sizeof(all) = 80 bytes
 * */
#define SIZEOFALL sizeof(struct all \
				{ \
				unsigned int age; \
				int id; \
				char name[64]; \
				INFO *info; \
				})
/*get the bigger one*/
#define MAX_2(X,Y) (X)>(Y)?(X):(Y)
#define MAX_3(X,Y,Z) (MAX_2(X,Y))>Z?(MAX_2(X,Y)):(Z)

/*using ptr to swap number*/
int self_swap_number(int *x, int *y)
{
	int t;
	t = *x;
	*x = *y;/*y to x*/
	*y = t;/*x to y*/
	/*wrong way because t-> y, y->x,they are the same*/
	// *y = t;
	// *x = *y;
}
/*static using*/
void self_sum_number(int x)
{
	static all = 0;
	printf("The all is %d\n",all);
	all += x;
}

int self_all_number()
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
	printf("The size of a is %d\n",sizeof(a));	
	return sizeof(a);
}

/*const*/
//const int a;/*a是一个常数不可修改*/
//int const a;/*同上*/
//const int *a;/*一个指向cosnt对象指针，不能通过这个指针修改这个值*/
//int * const a;/*指针无法修改*/
//int const * a const;/*都无法修改*/

/*get the length of one year in second*/
#define SECOND_YEAR (365*24*60*60)
//#define SECOND_YEAR_ADVANCED ((365*24*60*60)UL)
/*define macro for malloc like (char*)malloc(100*sizeof(char))*/
#define MALLOC(n,type) ((type*)(malloc((n) * sizeof(type))))

#define _APP_DATA_TYPE_
#endif 
