#ifndef DATA_H_
#define DATA_H_

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

/*using like DESKTOP *desktop,desktop.linux.fedora*/
/*
typedef struct linux{
		char fedora[32];
		char ubuntu[32];
		char centos[32];
}LINUX;

typedef struct desktop{
		char mac[64];
		char win[64];
		LINUX *linux;	
}DESKTOP;
*/


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


#endif 
