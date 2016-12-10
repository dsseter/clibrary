#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"



/*
 *带有头节点的链表
 */
int initLinkedList(LinkedNode** linked_node)
{
	LinkedNode * ln = (LinkedNode*) malloc(sizeof(LinkedNode));
	if(!ln)
	{
		printf("malloc is failure, in initLinkedList\n");
		return 1;
	} ln->next = NULL; ln->data = NULL;
	*linked_node = ln;
	return 0;
}

/*
 *index是下标  从0开始到length-1结束
 * */
int deleteLinkedList(LinkedNode * linked_node, int index)
{
	if(!linked_node || index < 0)
	{
		printf("linked_node is NULL or index is %d, in deleteLinkedList\n", index);
		return 1;
	}
	LinkedNode* tnode = linked_node, *dtnode= NULL;
	int i = 0;
	while(i<index && tnode->next)
	{
		tnode = tnode->next;
		i++;
	}
	if(!tnode->next)
	{
		printf("index >= length of linked_node, is %d, in deleteLinkedList\n", index);
		return 1;
	}
	dtnode = tnode->next;
	tnode->next = dtnode->next;
	free(dtnode);
	return 0;
}
int insertLinkedList(LinkedNode* linked_node, int index, void* data)
{
	if(!linked_node || index < 0)
	{
		printf("linked_node is NULL or index is %d, in insertLinkedList\n", index);
		return 1;
	}
	LinkedNode *ln = linked_node, *tnode = NULL;
	int i = 0;
	while(i<index && ln)
	{
		ln = ln->next;
		i++;
	}
	if(!ln)
	{
		printf("index >= length of linked_node, is %d, in insertLinkedList\n", index);
		return 1;
	}
	tnode = (LinkedNode*) malloc(sizeof(LinkedNode));
	if(!tnode)
	{
		printf("malloc is failure, in insertLinkedList\n");
		return 1;
	}
	tnode->next = ln->next;
	tnode->data = data;
	ln->next = tnode;
	//printf("insert %d\n", *(int*)(tnode->data));
	return 0;
}
void destoryLinkedList(LinkedNode* linked_node)
{
	LinkedNode *tnode = NULL;
	while(linked_node)
	{
		tnode = linked_node;
		linked_node = linked_node->next;
		free(tnode);
	}
}
int updateLinkedList(LinkedNode* linked_node, int index, void* data)
{
	if(!linked_node || index < 0)
	{
		printf("linked_node is NULL or index is %d, in updateLinkedList\n", index);
		return 1;
	}
	LinkedNode* tnode = linked_node;
	int i = 0;
	while(i<=index && tnode)
	{
		tnode = tnode->next;
		i++;
	}
	if(!tnode)
	{
		printf("index >= length of linked_node, is %d, in updateLinkedList\n", index);
		return 1;
	}
	tnode->data = data;
	return 0;
}

void* getLinkedList(LinkedNode* linked_node, int index)
{
	if(!linked_node || index < 0)
	{
		printf("linked_node is NULL or index is %d, in getLinkedList\n", index);
		return NULL;
	}
	int i = 0;
	LinkedNode* tnode = linked_node;
	while(i<=index && tnode)
	{
		tnode = tnode->next;
		i++;
	}
	if(!tnode)
	{
		printf("index >= length of linked_node, is %d, in getLinkedList\n", index);
		return NULL;
	}
	//printf("index %d, data %d", index, *(int*)(tnode->data));
	return tnode->data;
	
}
int lengthLinkedList(LinkedNode* linked_node)
{
	if(!linked_node)
	{
		printf("ln is NULL, in lengthLinkedList\n");
		return -1;
	}
	LinkedNode *tnode = linked_node->next;
	int count = 0;
	while(tnode)
	{
		count++;
		tnode = tnode->next;
	}
	return count;
}
void printLinkedList(LinkedNode const * ln, void (*printNode)(void *))
{
	if(!ln || ! printNode )
	{
		printf("ln is NULL or print function is NULL, in printLinkedList\n");
		return;
	}
	ln = ln->next;
	while(ln)
	{
		printNode(ln->data);
		ln = ln->next;
	}
	printf("\n");
}
int setLinkedList(LinkedNode* ln,int start_index, void* array, int len, int size)
{
	if(!ln || ! array || len < 0 || start_index < 0 )
	{
		printf("ln is NULL array is NULL, len < 0 or start_index < 0,  in setLinkedList\n");
		return 1;
	}
	for(int i=len-1; i>=0; i--)
	{
		if(insertLinkedList(ln, start_index, array+i*size))
		{
			printf("setLinkedList error\n");
			return 1;
		}
	}
	return 0;
}
int addNodeLinkedList(LinkedNode* ln, LinkedNode* node, int index)
{
	if(!ln || index < 0 || !node)
	{
		printf("ln is NULL, node is NULL or index is %d, in addNodeLinkedList\n", index);
		return 1;
	}
	LinkedNode *tmp = ln;
	int i = 0;
	while(i<index && tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if(!tmp)
	{
		printf("index >= length of ln, is %d, in addNodeLinkedList\n", index);
		return 1;
	}
	node->next = tmp->next;
	tmp->next = node;
	return 0;
}
