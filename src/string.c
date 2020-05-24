#include <stdlib.h>
#include <stdio.h> 
#include <string.h>
#include <assert.h>

/*
 * 移动字符串内容
 * 把倒数几个字符进行移位，如
 * abcdefghijk 移位M=3 即ijkabcdefgh
 * m = 3, i = 0, len = 11, s[11] = s[0] = a,s[0] = s[1] = b,s[0] - abcdefgh(8)
 * s[8] = s[9] = i j k 
 * three(m) rounds 
 * */
void move_nstr(char *s, int m)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int len;

	len = strlen(s);
	if (len == 0)
		return;

	if (m > len)/*超过原大小，直接赋值len*/
		m = len;

	/*逐一移位*/
	for (i = 0; i < len - m; i++)
		for (j = 0,s[len] = s[0]; j < len; j++)
			s[j] = s[j+1];

	if (len != strlen(s))/*判断是否变长字符串*/
		s[len] = '\0';/*结束符*/
}

/*new function memcpy*/
void *self_memcpy(void *dst, const char *src, int count)
{
	char *dt = dst;
	const char *sc = src;

	while(count--)
		*dt++ = *sc++;

	return dst;/*返回void指定类型数据*/
}

/*
* new function memcpy
* void *dst to char *dst which avoids warnings
*/
void *self_memmove(char *dst, const char *src, int count)
{
	char *dt = dst;
	const char *sc = src;
	/*
	* overlapping area
	* one way dst =< src: H |src|dst| L --> H |src|dst|xxxxx-count-xxxxx L
	* the other way dst > src: H |dst|src| L --> H |dst|src|xxxxx-count-xxxxx L 该处出现内存重叠，
	* 则在                     H |dst|xxxx-count-xxxxx|src|xxxxx-count-xxxxx L 
	* 对比内存位置
	* H              |xxxxxxx|hello|11111           L
	* H  |xxxxxxx|11111|hello|11111|                L
	* 不覆盖源串，新串可以被填入。
	*/	
	if (src >= dst)
		while(count--)
			*dt++ = *sc++;
	else{
		dt += count;
		sc += count;
		while(count--)
			*--dt = *--sc;
	}

	return dst;
}

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
/*new function strlen*/
int self_strlen1(const char *s)
{
	int len = 0;

	while(*s++ != '\0')
		len++;
	
	return len;
}

int self_strlen2(const char *s)
{
	const char *sc = s;

	/*from linux kernel tree source
	for(sc = s;*sc != '\0';sc++)
		;
	*/
	while(*++sc != '\0');/*提前判断到结束符*/

	return (sc - s);/*get the len*/
}

/*memset*/
void *self_memset(void *s, int c, int count)
{
	char *sc = s;

	/*copied from*/
	while(count--){
		*sc++ = c;
	}

	return s;
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
	return new_str;
}

