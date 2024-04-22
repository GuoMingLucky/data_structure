//2024_04_03 OJ刷题
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

typedef struct SLNode
{
	SLDataType val;
	struct SLNode* next;
}SLNode;

SLNode* SLBuyNode(SLDataType x)
{
	SLNode* newNode = (SLNode *)malloc(sizeof(SLNode));
	if(newNode ==NULL)
	{
		perror("newNode malloc failed");
		exit(1);
	}
	newNode ->val  = x;
	newNode ->next = NULL;
	 
	return newNode;
}

void SLPrint(SLNode *phead)
{
	SLNode *pcur =phead;
	while(pcur)
	{
		printf("%d->",pcur->val);
		pcur = pcur ->next;
	}
	printf("\n");
}

int ysf(int m,int n)
{
	SLNode* Head = SLBuyNode(1);
	SLNode* newNode = NULL,*tail = Head;
	SLNode* cur = Head;
	SLNode* prev = NULL;
	
	int i = 2;
	for(;i<=m;i++)
	{
		newNode = SLBuyNode(i);
		tail ->next = newNode;
	  tail = newNode;
	}
	tail ->next = Head;    //这样才构成一个环
	
	int count = 1;
	while(cur ->next !=cur)
	{
		if(count == n)
		{
			SLNode *ptemp = cur->next;
			prev ->next = ptemp;
			free(cur);
			cur = ptemp;
			count = 1;	
		}
		else{
			prev = cur;
			cur = cur ->next; 
			count++;
		}
	}
	//SLPrint(Head);
	return 	cur ->val;
}

void test1()
{
	int ret = ysf(5,2);
	printf("ret = %d\n",ret);
}

int main()
{
	//1.环形链表的约瑟夫问题
	//思路分析：有n个人，他们值，也就是编号为1开始到n
	//遍历循环单向链表，count =1.每遇到一个人，count++；
	//当count = m时，free掉当前人，count=1。接着往后遍历，count++；
	//直到 只剩下最后一个人，return 最后一个人。
	
	test1();
	
	return 0;	
}