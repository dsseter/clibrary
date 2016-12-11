/*
 *一种带头结点的链式队列
 * */

typedef struct LinkedQueueNode
{
	void* data;
	struct LinkedQueueNode* next;
} LinkedQueueNode;

typedef struct LinkedQueue
{
	struct LinkedQueueNode* tail;
	struct LinkedQueueNode* head;
	int size;
} LinkedQueue;

int initLinkedQueue(LinkedQueue **);
int enLinkedQueue(LinkedQueue*, void*);
void* deLinkedQueue(LinkedQueue*);
void destoryLinkedQueue(LinkedQueue*);
int isEmptyLinkedQueue(LinkedQueue*);
void* getFrontLinkedQueue(LinkedQueue*);
int lengthLinkedQueue(LinkedQueue*);
void printLinkedQueue(LinkedQueue const*, void(*)(void const*));
int setLinkedQueue(LinkedQueue*, void*, int, int);
