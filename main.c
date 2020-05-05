#include <stdio.h>
#include <string.h>
#include "app_data_type.h"
#include "app_self_file.h"
#include "app_endian_type.h"
#define VERSION "v2.2rc1"
extern void get_memory(char **ptr, int n);
extern void res_get_memory();
extern void get_memory_zero(unsigned int flag);
extern void self_strcpy(char *dst, const char *src);
extern char *copy_string(const char *src);
/*main function*/
int main(void)
{ 
	printf("back to interviewing\n");
	printf("The size of them are %lu for struct, %lu for union in same data \n", SIZEOFSTRUCT, SIZEOFUNION);
	printf("The fixed structs is %lu\n",SIZEOFALL);
	int res1,res2;
	int x = 9;
	int y = 29;
	char *string = NULL;
	char *str = NULL;
	res1 = file_size_withf("test.txt"); 
	res2 = file_size_withoutf("test.txt"); 
	printf("The size of file is %d,and %d\n",res1,res2);
	printf("The biggest one is %d %d\n",MAX_2(1,2),MAX_3(1,2,3));
	self_swap_number(&x,&y);
	printf("The swap numnber is %d %d\n",x,y);
	self_all_number();	
	size_space_full();
	get_memory(&string,100);/*pass the ptr*/
	strcpy(string,"hello");
	printf("The string is %s\n",string);
	printf("The add is %p\n",&string);
	res_get_memory();
	get_memory_zero(2);
	printf("The second is %d\n",SECOND_YEAR);
	char dst[64] = "";
	char src[64] = "watson";
	self_strcpy(dst,src);
	printf("The dst is %s\n",dst);
	printf("The dst string is %s\n",copy_string(src));
	return 0;
}
