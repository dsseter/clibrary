
/**
 * 使用顺序表的栈
 */

typedef struct Stack
{
	void** base;
	void** top;
	int size;
	int data_size;
} Stack;

int initStack(Stack**, int);
void destoryStack(Stack*);
void clearStack(Stack*);
int isEmptyStack(Stack const*);
void* popStack(Stack*);
int lengthStack(Stack*);
int pushStack(Stack*, void*);
void* peekStack(Stack*);
void printStack(Stack*, void(*)(void*));
int setStack(Stack*, void*, int, int);

