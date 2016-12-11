#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#define STACK_INIT_LEN 50
#define STACK_INC_LEN 10
/** 
typedef struct Stack
{
	void** base;
	void** top;
	int size;
	int data_size;
} Stack;
*/
int initStack(Stack** stack,int data_size)
{
	void** st_base = (void**) malloc(sizeof(void*)*STACK_INIT_LEN);
	Stack* st = (Stack*) malloc(sizeof(Stack));
	//printf("%d\n", sizeof(void*)*STACK_INIT_LEN);
	if(!st_base || !st)
	{
		printf("malloc is error in initStack\n");
		return 1;
	}
	st->size = STACK_INIT_LEN;
	st->data_size = sizeof(void*);
	st->base = st->top = st_base;
	*stack = st;
	return 0;

}
void destoryStack(Stack* stack)
{
	if(!stack)
	{
		printf("stack is NULL in destoryStack\n");
		return;
	}
	free(stack->base);
	free(stack);
}
void clearStack(Stack* stack)
{
	if(!stack)
	{
		printf("stack is NULL in clearStack\n");
		return;
	}
	stack->top = stack->base;
}
/**
 * 空返回1
 */
int isEmptyStack(Stack const* stack)
{
	if(!stack)
	{
		printf("stack is NULL in isEmptyStack\n");
		return 1;
	}
	return stack->base == stack->top? 1:0;
}
void* popStack(Stack* stack)
{
	if(!stack)
	{
		printf("stack is NULL in popStack\n");
		return NULL;
	}
	if(stack->base == stack->top)
	{
		printf("stack is empty in popstack\n");
		return NULL;
	}
	stack->top -= stack->data_size;
	return  *(stack->top);
}

int lengthStack(Stack* stack)
{
	if(!stack)
	{
		printf("stack is NULL in lengthStack\n");
		return 0;
	}
	return (stack->top - stack->base)/stack->data_size;
}
int pushStack(Stack* stack, void* data)
{
	if(!stack)
	{
		printf("stack is NULL in popStack\n");
		return 1 ;
	}
	void** st_base = NULL;
	if((stack->top - stack->base)/stack->data_size == stack->size)
	{
		st_base = (void**) realloc(stack->base, (stack->size+STACK_INC_LEN)*stack->data_size);
		if(!st_base)
		{
			printf("realloc is error in pushStack\n");
			return 1;
		}
		stack->top = st_base + stack->size * stack->data_size;
		stack->base = st_base;
		stack->size += STACK_INC_LEN;
	}
	printf("%d, %p, %p, %p\n", *(int*)data, data, stack->base, stack->top);
	*(stack->top) = data;
	stack->top += stack->data_size;
	printf("%d, %p, %p, %p\n", *(int*)data, data, stack->base, stack->top - stack->data_size);
	return 0;
}
/*
 *返回栈顶元素
 * */
void* peekStack(Stack* stack)
{
	if(!stack)
	{
		printf("stack is NULL in peekStack\n");
		return NULL;
	}
	if(stack->base == stack->top)
	{
		printf("stack is empty in peekstack\n");
		return NULL;
	}
	return *(stack->top - stack->data_size);
}
void printStack(Stack* stack, void(*print)(void*))
{
	if(!stack)
	{
		printf("stack is NULL in printStack\n");
		return ;
	}
	if(stack->base == stack->top)
	{
		printf("stack is empty in printtack\n");
		return ;
	}
	void** st_base = stack->base;
	int *a = NULL;
	while(st_base < stack->top)
	{
		printf("%p, %p, %d, %d \n", st_base, *st_base, stack->data_size, *(int*)*st_base );

		st_base += stack->data_size;
	}
	printf("\n");
}
int setStack(Stack* stack, void* array, int len, int data_size)
{
	if(!stack)
	{
		printf("stack is NULL in setStack\n");
		return 1;
	}
	for(int i=0; i< len; i++)
	{
		if(pushStack(stack, array+i*data_size))
			return 1;
	}
	return 0;
}

