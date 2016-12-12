#include<stdio.h>
#include"stack.h"

#define LEN 8 

void printdata(void* data)
{
	printf("%d,", *(int*)data);
}
/**
 *
 *gcc 
 *void* sizeof 8
 *void sizeof 1
 *int sizeof 4
 *int* sizeof 8
 * /

int main(void)
{
	int array[LEN] = {0};
	int result = -1;
	Stack * stack = NULL;
	for(int i=0; i<LEN; i++)
		array[i] = i;
	initStack(&stack);
	pushStack(stack, array);
	pushStack(stack, array+1);
	result = lengthStack(stack);
	printf("length of the stack is %d\n", result);
	printStack(stack, printdata);
	result = *(int*)popStack(stack);
	printf("data poped from the stack is %d\n", result);
	setStack(stack, array, LEN, sizeof(int));
	printStack(stack, printdata);
	destoryStack(stack);
	return 0;
}
