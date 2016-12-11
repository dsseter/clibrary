#include<stdio.h>
#include"stack.h"

#define LEN 8 

void printdata(void* data)
{
	printf("%d,", *(int*)data);
}

int main(void)
{
	int array[LEN] = {0};
	int result = -1;
	Stack * stack = NULL;
	for(int i=0; i<LEN; i++)
		array[i] = i;
	initStack(&stack, sizeof(int*));
//	printf("%d", sizeof(int*));
//	pushStack(stack, array);
//	pushStack(stack, array+1);
//	result = lengthStack(stack);
//	printf("length of the stack is %d\n", result);
//	printStack(stack, printdata);
//	result = *(int*)popStack(stack);
//	printf("data poped from the stack is %d\n", result);
	setStack(stack, array, LEN, sizeof(int));
	printStack(stack, printdata);
	destoryStack(stack);
	return 0;
}
