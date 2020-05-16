#include <stdlib.h>
#include <stdio.h> #include <string.h>
#include <assert.h>

/*reading the digit from string*/
void self_get_digits(const char *str)
{
	assert(str);
	int num = 0;
	/*
	 * 123de1234jlads1
	 * 123 1234 1(1无法打印)xxx
	 * 作为结果
	 */

	while (*str != '\0'){
		if (*str >= '0' && *str <= '9'){
			num = 10*num + *str - '0';
			if ( num == 0){
				printf("The num is %d\n",num);
			}
		} else{
			if (num != 0){
				printf("The num is %d\n",num);
			}

			num = 0;
		}
		str++;
	}
}

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

/*mystrncpy*/
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

