#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <stdbool.h>

typedef int QueueDataType;
//������еĽڵ㣬�����ǵ�����
typedef struct QueueNode 
{
	QueueDataType data;
	struct QueueNode* next;
}QueueNode;
//ͨ��һ���ṹ���������ṹ������ĳ�Ա��Ҳ���ǲ��������ָ�롣
//ͨ���ṹ��Queue����������ĳ�Ա��������һ��Ҳ���Է��ʳ�Ա������ĳ�Ա����

typedef struct Queue
{ 
	QueueNode *phead;  
	QueueNode *ptail; 
	int size;         //��Ч�����ݸ�����Ŀ����ͳ�ƶ��еĽڵ����
}Queue;

void QueueInit(Queue *pq);
void QueueDestroy(Queue *pq);
void QueuePush(Queue *pq,QueueDataType x);
void QueuePop(Queue *pq);
QueueDataType QueueFront(Queue *pq);
QueueDataType QueueBack(Queue *pq);
int QueueSize(Queue *pq);
bool QueueEmpty(Queue *pq);
