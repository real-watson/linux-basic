#include <stdio.h>
#include "app_data_type.h"
#include "app_self_file.h"
#include "app_endian_type.h"
#define VERSION "v2.2rc1"
/*main function*/
int main(void)
{
	printf("back to interviewing\n");
	printf("The size of them are %lu for struct, %lu for union in same data \n", SIZEOFSTRUCT, SIZEOFUNION);
	printf("The fixed structs is %lu\n",SIZEOFALL);
	int res1,res2;
	int x = 9;
	int y = 29;
	res1 = file_size_withf("test.txt"); 
	res2 = file_size_withoutf("test.txt"); 
	printf("The size of file is %d,and %d\n",res1,res2);
	printf("The biggest one is %d %d\n",MAX_2(1,2),MAX_3(1,2,3));
	self_swap_number(&x,&y);
	printf("The swap numnber is %d %d\n",x,y);
	return 0;
}
