
#include "SList.h"

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
SLNode* SLNodeFind(SLNode** pphead, SLDataType c)
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
void SLNodeInsert(SLNode** pphead, SLDataType c, SLDataType x)
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
void SLNodePrint(SLNode* phead)
{
	assert(phead);
	SLNode* cur = phead;
	while (cur)
	{
		printf("%c-> ", cur->data);
		cur = cur->next;
	}
}
//ɾ
void SLNodeErase(SLNode** pphead, SLDataType x)
{
	assert(pphead);
	assert(*pphead);
	SLNode* cur = *pphead;
	SLNode* prev = *pphead;

	if ((*pphead)->data == x)  //ͷɾ
	{
		SLNode* newhead = (*pphead)->next;
		free(*pphead);
		*pphead = newhead;
		return;
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

void SLChangeData(SLNode** pphead, SLDataType x, SLDataType c)
{
	SLNode* Find = SLNodeFind(pphead, x);
	if (Find != NULL)
		Find->data = c;
	else
	{
		printf("�ı��ַ�ʧ�ܣ�û���ҵ����ַ�\n");
		exit(1);
	}
}
//����
void SLNodeInsertBack(SLNode** pphead, SLDataType c)
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

//FILE* pFile;
//
//void get_time()
//{
//	time_t timep;
//	time(&timep);
//	fprintf(pFile, "%s", ctime(&timep));
//	//Wed Apr 10 14:36:57 2024
//}
//void saveContext(SLNode* pcur)
//{
//	pFile = fopen("my_file.txt", "w+");
//	if (pFile == NULL) 
//	{
//		perror("open my_file.txt failed");
//		return 1;
//	}
//	else 
//	{
//		while (pcur)
//		{
//			fwrite(&(pcur->data), sizeof(pcur->data), 1, pFile);
//			pcur = pcur->next;
//		}
//		get_time();
//
//		fclose(pFile);
//	}
//}
//void getContext(SLNode** pcur)
//{
//	assert(pcur);
//	pFile = fopen("my_file.txt", "r+");
//
//	SLNode info;
//	while (fread(&info, sizeof(info), 1, pFile))
//	{
//		SLNodeInsertBack(pcur, info.data);
//		//printf("��ȡ���ݳɹ�\n");
//	}
//	printf("\n��ȡ���ݳɹ�\n");
//	get_time();
//	fclose(pFile);
//}
