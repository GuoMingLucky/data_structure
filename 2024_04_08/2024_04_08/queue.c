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
	//����һ���µĽڵ�
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
	//һ���ڵ�  ����ڵ�
	//һ�ν�����   ���ν�����
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
	//�������ν����ã�һ�����õ�ͷ�ĵ�ַ��һ�����õ�ͷ�����ֵ
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
	
	return p->size; //p->size������Ƕ�������Ч�ڵ�ĸ���
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
	//����Ļ����Ǿ��޽ڵ㣬���ʽΪ�棬����true
	//��֮��������Ļ������ʽΪ�٣�����false
}