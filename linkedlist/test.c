#include"linkedlist.h"
#include<stdio.h>

void printint(void* data)
{
	printf("%d",  *(int*)(data));
}
int main(void)
{
	int tmpdata = -1;
	int array[5] = { 0, 1, 2, 3, 4};
	int array1[4] = {5, 6 ,7 ,8};
	LinkedNode *ln = NULL;
	initLinkedList(&ln);
	insertLinkedList(ln, 0,  &tmpdata);
	setLinkedList(ln, 0, array, 5, sizeof(int));
	int len = lengthLinkedList(ln);
	printf("len %d\nnode of 0 index is deleted\n", len);
	deleteLinkedList(ln, 0);
	len = lengthLinkedList(ln);
	printf("len %d\n", len);
	printLinkedList(ln, printint);
	setLinkedList(ln, 0, array1, 4, sizeof(int));
	printLinkedList(ln, printint);

}
