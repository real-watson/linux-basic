#include <stdlib.h>
#include <stdio.h> #include <string.h>
#include <assert.h>
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

