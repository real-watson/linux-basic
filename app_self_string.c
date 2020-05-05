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

