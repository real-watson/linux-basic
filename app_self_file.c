#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 1024
/*copy lines to the other file*/
void copy_long_lines(FILE *in, FILE *out)
{
	char buff[MAX_LINE] = "";
	if (NULL == in || NULL == out){
		return;
	}
	/*
	while(fgets(buff,MAX_LINE,in) != NULL){
		fputs(buff,out);
	}
	*/
	while(1){
		if (fgets(buff,MAX_LINE,in) == NULL){
			break;
		}
		fputs(buff,out);
	}
}
/*read one file and return its size*/
int file_size_withf(const char *filename)
{
	FILE *file = fopen(filename,"rb");
	char buff[1024] = "";
	int res;
if (NULL == file){
		printf("Fopen error\n");
		return -1;
	}

	res = fread(buff,sizeof(char),1024,file);
	if (-1 == res){
		printf("Fread error\n");
		return -1;
	}
	return res;
}

/*read one file and return its size*/
int file_size_withoutf(const char *filename)
{
	int fd;
	char buff[1024] = "";
	int len;

	fd = open(filename,"O_RDONLY","0600");
	if (-1 == fd){
		printf("Open error\n");
		return -1;
	}

	len = read(fd,buff,1024);
	if (-1 == len){
		printf("Read error\n");
		return -1;
	}	
	return len;
}

