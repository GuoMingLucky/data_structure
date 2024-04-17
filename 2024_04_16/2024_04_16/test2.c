#define _CRT_SECURE_NO_WARNINGS 1
//���������ɾ�Ĳ�
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

typedef char SLDataType;

typedef struct SLNode
{
	SLDataType data;
	struct SLNode* next;
}SLNode;

SLNode* SLNodeBuyNode(SLDataType c)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("mallocinit failed\n");
		exit(1);
	}

	newnode->data = c;
	newnode->next = NULL;

	return newnode;
}

void SLNodeInit(SLNode** pphead, SLDataType c)
{
	assert(pphead);
	*pphead = SLNodeBuyNode(c);
}

void SLNodeDestroy(SLNode** pphead)
{
	assert(pphead);
	SLNode* cur = *pphead;
	SLNode* next = cur->next;
	while (cur != NULL)
	{
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
}
//��
SLNode* SLNodeFind(SLNode **pphead,SLDataType c)
{
	assert(pphead);
	if ((*pphead)->data == c)
	{
		return *pphead;
	}
	else
	{
		SLNode* cur = *pphead;
		while (cur)
		{
			if (cur->data == c)
			{
				return cur;
			}
			cur = cur->next;
		}
	}
	return NULL;
}
//��
void SLNodeInsert(SLNode** pphead, SLDataType c,SLDataType x)
{
	assert(pphead);
	if (*pphead == NULL)
	{
		*pphead = SLNodeBuyNode(c);
		return;
	}
	else
	{
		SLNode* find = SLNodeFind(pphead, x);
		if (find != NULL)
		{
			SLNode* next = find->next;
			SLNode* newNode = SLNodeBuyNode(c);

			newNode->next = next;
			find->next = newNode;
		}
		else
		{
			printf("����ʧ�ܣ�û���ҵ����ַ�\n");
			exit(1);
		}
	}
}
void SLNodePrint(SLNode *phead)
{
	assert(phead);
	SLNode* cur = phead;
	while (cur)
	{
		printf("%c-> ",cur->data);
		cur = cur->next;
	}
}
//ɾ
void SLNodeErase(SLNode **pphead,SLDataType x)
{
	assert(pphead);
	assert(*pphead);
	SLNode* cur  = *pphead;
	SLNode* prev = *pphead;

	if ((*pphead)->data == x)  //ͷɾ
	{
		SLNode *newhead = (*pphead)->next;
		free(*pphead);
		*pphead = newhead;
		return ;
	}

	while (cur != NULL)
	{
		if (cur->data == x)
		{
			prev->next = cur->next;
			free(cur);
			return;
		}
		prev = cur;
		cur = cur->next;
	}
	printf("ɾ��ʧ��,û�и��ַ�\n");
	exit(1);
}
//��

void SLChangeData(SLNode **pphead,SLDataType x ,SLDataType c)
{
	SLNode* Find = SLNodeFind(pphead,x);
	if (Find != NULL)
		Find->data = c;
	else
	{
		printf("�ı��ַ�ʧ�ܣ�û���ҵ����ַ�\n");
		exit(1);
	}
}
										//����
void SLNodeInsertBack(SLNode **pphead,SLDataType c) 
{
	assert(pphead);
	if (*pphead == NULL) 
	{
		*pphead = SLNodeBuyNode(c);
		return;
	}
	else 
	{
		SLNode* cur = *pphead;
		while (cur->next) 
		{
			cur = cur->next;
		}
		cur->next = SLNodeBuyNode(c);
	}
}

FILE* pFile;

void get_time()
{
	time_t timep;
	time(&timep);
	fprintf(pFile, "%s", ctime(&timep));
	//Wed Apr 10 14:36:57 2024
}
void saveContext(SLNode *pcur) 
{
	pFile = fopen("my_file.txt", "w+");
	
	while (pcur)
	{
		fwrite(&(pcur->data), sizeof(pcur->data), 1, pFile);
		pcur = pcur->next;
	}
	get_time();

	fclose(pFile);
}
void getContext(SLNode **pcur) 
{	
	assert(pcur);
	pFile = fopen("my_file.txt","r+");
	
	SLNode info;
	while (fread(&info,sizeof(info),1,pFile)) 
	{	
		SLNodeInsertBack(pcur,info.data);
		//printf("��ȡ���ݳɹ�\n");
	}
	printf("\n��ȡ���ݳɹ�\n");
	get_time();
	fclose(pFile);
}
void test02()
{
	SLNode SL;
	struct SLNode* pcur = &SL;
	SLNodeInit(&pcur, 'a');
	SLNodeInsert(&pcur, 'b', 'a');//a->b
	SLNodeInsert(&pcur, 'c', 'a');
	SLNodeInsert(&pcur, 'd', 'a');
	SLNodeInsert(&pcur,'e','a');
	SLNodePrint(pcur);   //a->e->d->c->b->
	//fscanf(stdout,"%d",i);     //���ļ��л�ȡ�ı���Ϣ
	//sprintf(pFile,"a->e->d->c->b->");  
	//saveContext(pcur);

	printf("\n");                     //�ַ�g�Ҳ�����
//	SLNodeInsert(&pcur, 'a', 'g');
//	SLNodePrint(pcur);   //a->e->d->c->b->

	printf("\n");
	SLNodeErase(&pcur, 'a');
	SLNodePrint(pcur);   //e->d->c->b->
	printf("\n");
	SLNodeErase(&pcur, 'd');
	SLNodePrint(pcur);   //e->c->b->
	printf("\n");
//	SLNodeErase(&pcur, 'g');
//	SLNodePrint(pcur);  //ʧ��
	printf("\n");
	SLChangeData(&pcur,'e','a');
	SLNodePrint(pcur);  //a->c->b
	printf("\n");
	SLChangeData(&pcur, 'c', 'b');
	SLNodePrint(pcur);  //a->b->b

	//printf("\n");
	//SLNodeErase(&pcur, 'a');
	//SLNodeErase(&pcur, 'b');
	//SLNodeErase(&pcur, 'b');
	//SLNodePrint(pcur);  //a->b->b

	//SLNodeInsertBack(&pcur,'G');
	//SLNodePrint(pcur);  //a->b->b

//	SLChangeData(&pcur, 'b', 'c');   //�Ҳ���b��
//	SLNodePrint(pcur);  //a->c->c

	//close(pFile);
	saveContext(pcur);
	getContext(&pcur);

	SLNodeDestroy(&pcur);

}


int main()
{
	test02();

	return 0;
}
