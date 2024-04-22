//2024_04_03 OJˢ��
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
	tail ->next = Head;    //�����Ź���һ����
	
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
	//1.���������Լɪ������
	//˼·��������n���ˣ�����ֵ��Ҳ���Ǳ��Ϊ1��ʼ��n
	//����ѭ����������count =1.ÿ����һ���ˣ�count++��
	//��count = mʱ��free����ǰ�ˣ�count=1���������������count++��
	//ֱ�� ֻʣ�����һ���ˣ�return ���һ���ˡ�
	
	test1();
	
	return 0;	
}