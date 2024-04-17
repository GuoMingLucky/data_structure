#ifndef _PROJECT_PATH_H_
#define _PROJECT_PATH_H_
#define _CRT_SECURE_NO_WARNINGS 1
//#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

//单链表的增删改查
typedef char SLDataType;

typedef struct SLNode
{
	SLDataType data;
	struct SLNode* next;
}SLNode;

//创建一个节点
SLNode* SLNodeBuyNode(SLDataType c);
//节点的初始化
void SLNodeInit(SLNode** pphead, SLDataType c);
//销毁
void SLNodeDestroy(SLNode** pphead);
//查
SLNode* SLNodeFind(SLNode** pphead, SLDataType c);
//增
void SLNodeInsert(SLNode** pphead, SLDataType c, SLDataType x);
void SLNodePrint(SLNode* phead);
//删
void SLNodeErase(SLNode** pphead, SLDataType x);
//改
void SLChangeData(SLNode** pphead, SLDataType x, SLDataType c);
//插入
void SLNodeInsertBack(SLNode** pphead, SLDataType c);

#endif