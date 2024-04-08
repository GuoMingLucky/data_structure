#include"queue.h"

void QueueInit(Queue* p)
{
	assert(p);
	p->phead = p->ptail = NULL;
	p->size = 0;
}

void QueueDestroy(Queue* p) 
{	
	assert(p);
	QueueNode* cur = p->phead;
	while (cur) 
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	p->phead = p->ptail = NULL;
	p->size = 0;
}

void QueuePush(Queue* p,QueueDataType x)
{
	assert(p);
	//创建一个新的节点
	QueueNode * newNode = (QueueNode *)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		perror("malloc failed ");
		exit(1);
	}
	newNode->data = x;
	newNode->next = NULL;

	if (p->ptail) 
	{
		p->ptail->next = newNode;
		p->ptail = newNode;
	}
	else {
		p->ptail = p->phead = newNode;
	}
	p->size++;
}

void QueuePop(Queue* p) 
{
	assert(p);
	assert(p->size > 0);
	//一个节点  多个节点
	//一次解引用   二次解引用
	if (p->phead ->next == NULL) 
	{
		free(p->phead);
		p->phead = p->ptail = NULL;
	}
	else {
		QueueNode* newHead = p->phead->next;
		free(p->phead);
		p->phead = newHead;
	}
	p->size--;
}
QueueDataType QueueFront(Queue* p) 
{
	assert(p);
	assert(p->phead);
	//进行两次解引用，一次是拿到头的地址，一次是拿到头里面的值
	return p->phead->data;
}

QueueDataType QueueBack(Queue* p) 
{
	assert(p);
	assert(p->ptail);

	return p->ptail->data;
}

int QueueSize(Queue* p) 
{
	assert(p);
	
	return p->size; //p->size本身就是队列中有效节点的个数
}

bool QueueEmpty(Queue* p) 
{
	assert(p);
	if (p->phead) 
	{
		return false;
	}
	return true;
	//return p->size == 0;    
	//是零的话，那就无节点，表达式为真，返回true
	//反之，不是零的话，表达式为假，返回false
}