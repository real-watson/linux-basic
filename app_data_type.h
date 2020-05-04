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

#define _APP_DATA_TYPE_
#endif 
