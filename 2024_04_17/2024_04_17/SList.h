#ifndef _PROJECT_PATH_H_
#define _PROJECT_PATH_H_
#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//���������ɾ�Ĳ�
typedef char SLDataType;

typedef struct SLNode
{
	SLDataType data;
	struct SLNode* next;
}SLNode;

//����һ���ڵ�
SLNode* SLNodeBuyNode(SLDataType c);
//�ڵ�ĳ�ʼ��
void SLNodeInit(SLNode** pphead, SLDataType c);
//����
void SLNodeDestroy(SLNode** pphead);
//��
SLNode* SLNodeFind(SLNode** pphead, SLDataType c);
//��
void SLNodeInsert(SLNode** pphead, SLDataType c, SLDataType x);
void SLNodePrint(SLNode* phead);
//ɾ
void SLNodeErase(SLNode** pphead, SLDataType x);
//��
void SLChangeData(SLNode** pphead, SLDataType x, SLDataType c);
//����
void SLNodeInsertBack(SLNode** pphead, SLDataType c);

#endif