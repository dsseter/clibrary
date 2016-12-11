#include<stdio.h>
#include<stdlib.h>
#include"linkedqueue.h"

int initLinkedQueue(LinkedQueue ** lq)
{
	LinkedQueue *queue = (LinkedQueue*) malloc(sizeof(LinkedQueue));
	LinkedQueueNode *node = (LinkedQueueNode*) malloc(sizeof(LinkedQueueNode));
	if(!queue || !node)
	{
		printf("malloc is error in initLinkedQueue\n");
		return 1;
	}
	node->data = node->next = NULL;
	queue->head = queue->tail = node;
	queue->size = 0;
	*lq = queue;
	return 0;
}
int enLinkedQueue(LinkedQueue* lq, void* data)
{
	if(!lq)
	{
		printf("lq is NULL in enLinkedQueue\n");
		return 1;
	}
	LinkedQueueNode *node = (LinkedQueueNode*) malloc(sizeof(LinkedQueueNode));
	if(!node)
	{
		printf("malloc is error in initLinkedQueue\n");
		return 1;
	}
	node->data = data;
	node->next = NULL;
	lq->tail->next = node;
	lq->tail = node;
	lq->size++;
	return 0;
}

void* deLinkedQueue(LinkedQueue* lq)
{
	if(!lq)
	{
		printf("lq is NULL\n");
		return NULL;
	}
	if(!lq->size)
	{
		printf("queue is empty in deLinkedQueue\n");
		return NULL;
	}
	void* data = NULL;
	LinkedQueueNode* node = lq->head->next;
	lq->head->next = node->next;
	if(node == lq->tail)
		lq->tail = lq->head;
	lq->size--;
	data = node->data;

	free(node);
	return data;
}
void destoryLinkedQueue(LinkedQueue* lq)
{
	LinkedQueueNode* node = lq->head;
	LinkedQueueNode* tmp = NULL;
	while(node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(lq);
}

int isEmptyLinkedQueue(LinkedQueue* lq)
{
	if(!lq)
	{
		printf("lq is NULL in isEmptyLinkedQueue\n");
		return 0;
	}
	return lq->size? 1: 0;
}


void* getHeadLinkedQueue(LinkedQueue* lq)
{
	if(!lq)
	{
		printf("lq is NULL in getHeadLinkedQueue\n");
		return NULL;
	}
	if(!lq->size)
	{
		printf("length of lq is zero\n");
		return NULL;
	}
	return lq->head->next->data;
}

int lengthLinkedQueue(LinkedQueue* lq)
{
	if(!lq)
	{
		printf("lq is NULL in lengthLinkedQueue\n");
		return 0;
	}
	return lq->size;
}

/**
 *输出队列中所有的数据
 */
void printLinkedQueue(LinkedQueue const* lq, void(*print)(void const* data))
{
	if(!lq)
	{
		printf("lq is NULL in printLinkedQueue\n");
		return;
	}
	LinkedQueueNode* node = lq->head->next;
	printf("head ");
	while(node)
	{
		print(node->data);
		node = node->next;
	}
	printf(" tail\n");
}

/**
 *一次入队多个数据
 */
int setLinkedQueue(LinkedQueue* lq, void* data_array, int array_len, int data_size)
{
	if(!lq)
	{
		printf("lq is NULL in setLinkedQueue\n");
		return 1;
	}
	for(int i=0; i<array_len; i++)
	{
		if(enLinkedQueue(lq, data_array+(i*data_size)))
		{
			return 1;
		}
	}
	return 0;
}

