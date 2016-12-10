
typedef struct LinkedNode{
	void* data;
	struct LinkedNode* next;
} LinkedNode;
/*
 *带有头节点的链表
 * */
int initLinkedList(LinkedNode**);
int deleteLinkedList(LinkedNode *, int);
int insertLinkedList(LinkedNode *, int, void*);
void destoryLinkedList(LinkedNode *);
int updateLinkedList(LinkedNode*, int, void*);
void* getLinkedList(LinkedNode*, int);
int lengthLinkedList(LinkedNode*);
//打印整个链表, 参数列表含义: 链表指针, 自定义打印函数指针
void printLinkedList(LinkedNode const*, void (*)(void *));
//insert多个节点内容. 参数列表含义: 链表指针, 插入下标, 带插入的数组指针, 数组长度, 数组单位节点大小
int setLinkedList(LinkedNode*, int, void*, int, int);
int addNodeLinkedList(LinkedNode*, LinkedNode*, int);
