#ifndef _APP_STACK_HEAP_
#include <stdio.h>
#include <stdlib.h>

#define STACK int

void push(STACK value);
void pop(void);
STACK top(void);
int is_empty(void);
int is_full(void);
#define _APP_STACK_HEAP_
#endif
