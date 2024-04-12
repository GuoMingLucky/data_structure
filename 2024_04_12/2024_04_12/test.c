#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ROWS 2
#define COLS 3
#define N 32


void test01() 
{
	//初始化字符指针数组
	char* a[ROWS][COLS];
	//1.先为各个字符串指针数组中的每一个元素分配内存空间
	for (int i = 0; i < ROWS; i++) 
	{
		for (int j = 0; j < COLS; j++) 
		{
			a[i][j] = (char *)malloc(sizeof(char)*N);
			if (a[i][j] == NULL)
			{
				perror("malloc failed");
			}
			strcpy(a[i][j],"hello "); 
		}
	}
	//修改
	char* str = "world1234511312341355 ";
	free(a[0][1]);
	a[0][1] = (char*)malloc(strlen(str) + 1); 
	if(a[0][1] != NULL)
		strcpy(a[0][1],str);//修改的内容按照参数修改

	//打印字符指针数组
	for (int i = 0; i < ROWS; i++) 
	{
		for (int j = 0; j < COLS; j++) 
		{
			printf("%s",a[i][j]);
		}
	}
	//释放刚才分配的内存空间
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			free(a[i][j]);
		}
	}

	//free(a);  大错
}
typedef struct SLNode
{
	char data;
	struct SLNode* next;
}SLNode;

void SLNodeBuyNode(char c) 
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("mallocinit failed\n");
	}
	newnode->data = c;
	newnode->next = NULL;
}

void SLNodeInit(SLNode** pphead,char c) 
{
	assert(pphead);
	*pphead = (SLNode *)malloc(sizeof(SLNode));
	if (*pphead == NULL) 
	{
		perror("mallocinit failed\n");
	}
	(*pphead)->data = c;
	(*pphead)->next = NULL;
}

void SLNodeDestroy(SLNode** pphead) 
{
	assert(pphead);
	SLNode* cur = *pphead;
	SLNode* next = cur->next;
	while(cur !=NULL)
	{
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
}

void SLNodeInsert(SLNode** pphead, char c) 
{
	assert(pphead);
	if (*pphead == NULL) 
	{   

		(*pphead)->data =c;
		(*pphead)->next = NULL;
		return;
	}
	else 
	{
		SLNode *next = 
	}
}

void test02() 
{
	SLNode SL;
	struct SLNode* pcur = &SL;
	SLNodeInit(&pcur,'a');
	SLNodeDestroy(&pcur);
}

int main() 
{
	test01();
	test02();

	return 0;
}