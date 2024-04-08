#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>

typedef int QueueDataType;
//定义队列的节点，基础是单链表
typedef struct QueueNode 
{
	QueueDataType data;
	struct QueueNode* next;
}QueueNode;
//通过一个结构体来操作结构体里面的成员，也就是操作里面的指针。
//通过结构体Queue来访问里面的成员变量，进一步也可以访问成员变量里的成员变量

typedef struct Queue
{ 
	QueueNode *phead;  
	QueueNode *ptail; 
	int size;         //有效的数据个数，目的是统计队列的节点个数
}Queue;

void QueueInit(Queue *pq);
void QueueDestroy(Queue *pq);
void QueuePush(Queue *pq,QueueDataType x);
void QueuePop(Queue *pq);
QueueDataType QueueFront(Queue *pq);
QueueDataType QueueBack(Queue *pq);
int QueueSize(Queue *pq);
bool QueueEmpty(Queue *pq);
