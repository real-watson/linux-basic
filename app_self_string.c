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

char *copy_string(const char *src)
{
	assert(src);
	int len = 0;
	char *new_str = NULL;

	len = strlen(src);
	new_str = (char*)malloc(len + 1);

	if (NULL == new_str){
		return NULL;
	}
	self_strcpy(new_str,src);
	return new_str;
}
