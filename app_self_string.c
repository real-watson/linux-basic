#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <assert.h>

/*valid digit*/
int valid_digit(const char c)
{
	if (c >= '0' && c <= '9')
		return 0;
	return 1;
}


/*get digit*/
void self_get_digits(const char *str)
{
	assert(str);
	int num = 0;
	int len = strlen(str);

	/*
	 * 123de1234jlads1
	 * 123 1234 1(1可以打印)xxx
	 * 作为结果
	 */

	while (len--){
		if (!valid_digit(*str)){
			num = 10*num + *str - '0';/*字符转数字*/
			if (!num)
				printf("The num is %d\n",num);
		}else{
			if (num != 0){
				printf("The num is %d\n",num);
				num = 0;
			}
		}

		str++;

		if (*str == '\0')/*结束符判断*/
			printf("The num is %d\n",num);
	}
}

/*new function strcmp*/
int self_strcmp(const char *src, char *dst)
{
	assert(src);
	assert(dst);
	unsigned char sc;
	unsigned char dt;

	while(1){
		sc = *src++;
		dt = *dst++;

		if (sc != dt)/*比较大小，不想等则肯定大小*/
			return sc < dt ? -1 : 1;
		if (!sc)/*相等情况下，若sc存在则break，返回0*/
			break;
	}
	return 0;	
}

/*new function strncmp*/
int self_strncmp(const char *src, char *dst, unsigned int count)
{
	assert(src);
	assert(dst);
	unsigned char sc;
	unsigned char dt;

	if (count == 0)
		return 0;

	while(--count){
		sc = *src++;
		dt = *dst++;
		if (sc != dt)
			return sc < dt ? -1 : 1;
		if (!sc)
			break;
	}
	return 0;
}
/*new function strcpy*/
void self_strcpy(char *dst, const char *src)
{
	int len = 0;
	assert(dst);
	assert(src);
	while(*src != '\0'){
		*dst++ = *src++;
	}
	*dst = '\0';
}

/*new function strncpy*/
char *self_strncpy(char *dst, const char *src, int size)
{
	if (0 == size){
		return dst;
	}
	while(size--){
		*dst = *src;
		if (*dst == '\0'){
			//return dst;
			break;
		}
		dst++;
		src++;
	}
	*dst = '\0';
	return dst;
}
/**copy_string*/
char *copy_string(const char *src)
{
	assert(src);
	int len = 0;
	char *new_str = NULL;

	new_str = (char*)malloc(strlen(src) + 1);

	if (NULL == new_str){
		goto failure;/*goto free*/
	}

	self_strcpy(new_str,src);
	free(new_str);
	return new_str;

failure:
	free(new_str);
	new_str = NULL;
}

