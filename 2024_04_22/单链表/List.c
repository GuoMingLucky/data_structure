//2024/04/02

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int ListDataType; 

typedef struct List
{
	ListDataType data;
	struct List *prev;
	struct List *next;
}ListNode;

ListNode *ListBuyNode(ListDataType x)
{
	ListNode* newNode = (ListNode *)malloc(sizeof(ListNode));
	if(newNode == NULL)
	{
		perror("malloc failed");
		exit(1);	
	}
	newNode -> data = x;
	newNode -> next = newNode ->prev = newNode;
}

void ListInit(ListNode **pphead,ListDataType x)
{
	*pphead = ListBuyNode(x);
}

void ListPrint(ListNode *phead)
{
		assert(phead);
		ListNode *cur = phead->next;
		while(cur !=phead)
		{
			printf("%d->",cur->data);
			cur = cur->next;
		}
		printf("NULL\n");
}

void ListPushBack(ListNode * phead,ListDataType x)
{
		assert(phead);
		
		ListNode *newNode = ListBuyNode(x);
		newNode ->next = phead;
		newNode ->prev = phead ->prev;
		phead -> prev ->next = newNode;
		phead -> prev = newNode;
}

void ListPushFront(ListNode *phead,ListDataType x)
{
		assert(phead);
		
		ListNode *newNode = ListBuyNode(x);
		newNode ->next = phead->next;
		newNode ->prev = phead;
		
		phead ->next ->prev = newNode;
		phead ->next = newNode;
}

void ListPopBack(ListNode *phead)
{
	assert(phead);
	assert(phead->next !=phead);
	
	ListNode *tail  = phead->prev;
	
	phead ->prev = tail->prev;
	tail ->prev ->next = phead;
		
	free(tail);
	tail = NULL;
	//phead->prev = NULL;
}

void ListPopFront(ListNode *phead)
{
	assert(phead);
	assert(phead ->next != phead);
	
	ListNode *del = phead->next;
	del -> next ->prev = phead;
	phead ->next = del ->next;
	free(del);
	del = NULL;
}

ListNode* ListFind(ListNode *phead ,ListDataType x)
{
	ListNode *pcur = phead->next;
	while(pcur!=phead)
	{
		if(pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur ->next;
	}
	return NULL;
}

void ListInsert(ListNode *pos,ListDataType x)
{
	assert(pos);
	
	ListNode *newNode = ListBuyNode(x);
	newNode ->next = pos->next;
	newNode ->prev = pos;
	pos ->next ->prev =newNode;
	pos ->next = newNode;
}

void ListErase(ListNode *pos)
{
	assert(pos);
	
	pos->next ->prev = pos->prev;
	pos->prev ->next = pos->next;
	free(pos);
	pos = NULL;
}

void ListDestroy(ListNode **pphead)
{
	assert(pphead);
	assert(*pphead);
	
	ListNode *pcur = (*pphead) ->next;
	ListNode *next =NULL;
	while(pcur ->next != *pphead)
	{
		next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(*pphead);
	*pphead = NULL;
}

int main()
{
	ListNode LN ;
	ListNode *plist = &LN;
	ListInit(&plist,-1);
	
	ListPushBack(plist,1);
	ListPushBack(plist,2);
	ListPushBack(plist,3);
	ListPushBack(plist,4); //1->2->3->4->NULL
	
	ListPushFront(plist,5);
	ListPushFront(plist,6);//6->5->1->2->3->4->NULL
	
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);//6->5->1->NULL
	
	ListPopFront(plist);//5->1->NULL

	ListNode *pos = ListFind(plist,1);
	ListInsert(pos,7);  //5->1->7->NULL
	pos = ListFind(plist,7);
	ListInsert(pos,8);  //5->1->7->8->NULL
	
	pos = ListFind(plist,8);
	ListErase(pos);  //5->1->7->NULL
	
	ListPrint(plist);
	
	ListDestroy(&plist);
	
	ListPrint(plist);
	
	return 0;	
}