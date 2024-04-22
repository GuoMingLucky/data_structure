#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

SLTNode *SLTBuyNode(SLTDataType x)
{
	SLTNode *newNode = (SLTNode *)malloc(sizeof(SLTNode));
	if(newNode ==NULL)
	{
		perror("malloc failed");
		exit(-1);	
	}
	newNode -> data = x;
	newNode-> next = NULL;
	
	return newNode;	
}

void SLTInit(SLTNode **pphead)
{
	//	printf("===========");
//	SLTNode *newNode = *pphead;
	if(*pphead == NULL)//{
//		newNode =(SLTNode *)malloc(sizeof(SLTNode));
//		if(newNode==NULL)
//		{
//			perror("malloc failed\n");
//			exit(-1);
//		}
//	}	
//	//printf("===========");
//	newNode->data = 0;
//	newNode->next = NULL;
	*pphead = SLTBuyNode(0);
}

void SLTPushBack(SLTNode **pphead,SLTDataType x)
{
	assert(pphead);
	SLTNode *newNode = NULL;
	
	newNode = SLTBuyNode(x);
	
	if(*pphead ==NULL)
	{
//		SLTNode *newNode = (SLTNode*)malloc(sizeof(SLTNode));
//		if(newNode ==NULL)
//		{
//			perror("malloc failed\n");	
//			exit(-1);
//		}	
//		newNode ->data = x;
//		newNode ->next = NULL;
	//	newNode = SLTBuyNode(x);
		*pphead = newNode; 
		return;
	}
	else
	{
//		SLTNode *newNode = (SLTNode*)malloc(sizeof(SLTNode));
//		if(newNode ==NULL)
//		{
//			perror("malloc failed\n");	
//			exit(-1);
//		}
		SLTNode *cur = *pphead;
		while(cur->next !=NULL)
		{
			cur = cur->next;
		}	
//		newNode->next = NULL;
//		newNode->data = x;
		cur->next = newNode;		
		return;
	}	
}

void SLTPushFront(SLTNode **pphead,SLTDataType x)
{
	assert(*pphead);
	SLTNode *newNode = *pphead;
	newNode = SLTBuyNode(x);
	
	if(*pphead ==NULL)
	{
		*pphead = newNode;
	}
	newNode ->next = *pphead;
	*pphead = newNode;
}

void SLTPopBack(SLTNode **pphead)
{
	assert(pphead);
	assert(*pphead);
	if((*pphead)->next ==NULL){
		free(*pphead);
		*pphead =NULL;
		return ;
	}
	SLTNode *prev = *pphead;
	while(prev->next->next !=NULL)
	{
		prev = prev->next;
	}
	free(prev->next);
	prev->next =NULL;	
}

void SLTPopFront(SLTNode **pphead)
{
	assert(pphead);
	assert(*pphead);
//	if((*pphead) ->next ==NULL)
//	{
//		free(*pphead);
//		*pphead = NULL;
//		return ;
//	}
	SLTNode *next = (*pphead) ->next;
	free(*pphead);
	*pphead = next;
}

void SLTPrint(SLTNode *ps)
{	
	assert(ps);
	while(ps)
	{
		printf("%d-> ",ps->data);
		ps = ps->next;
	}
	printf("NULL\n");
}
SLTNode *SLTFind(SLTNode *phead,SLTDataType x)
{
	assert(phead);
	SLTNode *cur = phead;
	while(cur != NULL)
	{
		if(cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void SLTInsert(SLTNode **pphead,SLTDataType x,SLTNode* pos)
{
	assert(pphead);
	assert(pos);
	assert(*pphead);
	
	SLTNode *prev = NULL;
	SLTNode *cur = *pphead;
	SLTNode *newNode = SLTBuyNode(x);
	
	if(*pphead ==pos)
	{
		newNode ->next = *pphead;
		*pphead= newNode;	
		return ;
	}
	
	while(cur != NULL)
	{
		if(cur == pos)
		{
			newNode->next = pos->next;
			prev->next = newNode;			
		}
		prev = cur;
		cur = cur->next;			
	}
} 

void SLTErase(SLTNode **pphead,SLTNode *pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);

	if(pos==*pphead)
	{
		*pphead = (*pphead)->next;
		free(pos);
		return ;
	}
	
	SLTNode* cur = *pphead;
	while(cur->next !=pos)
	{
		cur = cur->next;
	}
	cur->next = pos->next;
	free(pos);
	pos = NULL;
}

int main()
{
//	SLTNode *node1 = (SLTNode*)malloc(sizeof(SLTNode));
//	node1->data = 100;
//	
//	SLTNode *node2 = (SLTNode*)malloc(sizeof(SLTNode)); 
//	node2->data = 200;
//	
//	SLTNode *node3 = (SLTNode*)malloc(sizeof(SLTNode));
//	node3->data = 300;
//
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = NULL;
//	
//	SLTNode *plist = node1;
	SLTNode *plist = NULL;
	
	SLTInit(&plist);
	SLTPushBack(&plist,11);
	SLTPushFront(&plist,22);
	//SLTPopBack(&plist);
	//SLTPopFront(&plist);

	SLTNode* SLTRet = SLTFind(plist,11);
	//SLTInsert(&plist,33,SLTRet);
	SLTErase(&plist,SLTRet);
	SLTPrint(plist);	
	
	return 0;	
}