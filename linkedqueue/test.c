#include<stdio.h>
#include"linkedqueue.h"

#define LEN 10

void printdata(void const* data)
{
	printf("%d,", *(int*)data);
}
int main(void)
{

	int array[LEN] = {0};
	int ret_result = -1;
	for(int i=0; i<LEN; i++)
	{
		array[i] = i;
	}
	LinkedQueue* queue = NULL;
	initLinkedQueue(&queue);
	enLinkedQueue(queue, array);
	printLinkedQueue(queue, printdata);
	ret_result = lengthLinkedQueue(queue);
	printf("length of queue is %d\n", ret_result);
	ret_result = *(int*)deLinkedQueue(queue);
	printf("dequeue data is %d\n", ret_result);
	setLinkedQueue(queue, array, LEN, sizeof(int));
	printLinkedQueue(queue, printdata);
	ret_result = lengthLinkedQueue(queue);
	printf("length of queue is %d\n", ret_result);
	destoryLinkedQueue(queue);
	return 0;
}
