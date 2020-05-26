#ifndef UTIL_H_
#define UTIL_H_
extern void get_memory(char **ptr, int n);
extern void res_get_memory();
extern void get_memory_zero(unsigned int flag);
extern void self_strcpy(char *dst, const char *src);
extern char *copy_string(const char *src);
extern void memory_divide();
extern void self_get_digits(const char *str);
extern void bubble_sort (int *a,int n);
extern int self_strcmp(const char *src, char *dst);
extern int self_strncmp(const char *src, char *dst, unsigned int count);
extern int self_strlen1(const char *s);
extern int self_strlen2(const char *s);
extern void *self_memset(void *s, int c, int count);
extern void *self_memcpy(void *dst, const char *src, int count);
extern void *self_memmove(void *dst, const char *src, int count);
extern int calculate(int x, int y);
extern int file_size_withf(const char *filename);
extern int file_size_withoutf(const char *filename);
extern void move_nstr(const char *s, int m);
extern void reset_nbit(int x, unsigned int index);
#endif
