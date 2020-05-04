#include <assert.h>
#include <stdio.h>
#include "app_stack_heap.h"
#define SIZE 100

static STACK stack[SIZE];
static int top_element = -1;

void push(STACK value)
{
	assert(!is_full());
	top_element += 1;
	stack[top_element] = value;
}

void pop(void)
{
	assert(!is_empty());
	top_element -= 1;
}
STACK top(void)
{
	assert(!is_empty());
	return stack[top_element];
}

int is_empty()
{
	if (-1 == top_element){
		return 0;
	}else{
		return 1;
	}
}
int is_full()
{
	if ((SIZE-1) == top_element){
		return 0;
	}else{
		return 1;
	}
}
