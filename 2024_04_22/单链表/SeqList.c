//��̬˳����ʵ��
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
/*
typedef int SLDataType;  //��Ҫ��һ���������͸���������
#define N 100 //��Ҫ����С��������������������ĸĶ�

typedef struct Seqlist
{
	SLDataType arr[N];
	int size;   //��Ч���ݸ���	
}SL;          //�������������������

int main()
{
	SL sl = {0};
	int i = 0;

	for(i = 0;i<N;i++)
	{
		sl.arr[i] = i;
	}
	sl.size = N;

	for(i=0;i<sl.size;i++)
	{
		printf("%d ",sl.arr[i]);
	}
	printf("\n");
	return 0;	
}*/
/*
typedef int SeqDataType;  //�����������ת��
													//�洢�����ݽṹ����
typedef struct Seqlist
{
	SeqDataType *arr;  //�������ʼλ��
	int size;	    //�����е���Ч����
	int capacity;  //����Ĵ洢������С
}SL;
//
void checkCapacity(SL *point)
{ 	
		if(point->size == point->capacity)
		{
			int newcapacity = point->capacity == 0 ? 4 : 2*point->capacity;
			SeqDataType *tmp = (SeqDataType*)realloc(point->arr,sizeof(SL)*newcapacity);	
			if(tmp == NULL)
			{
				perror("realloc failed");
				exit(-1);	
			}
			point->arr = tmp;
			point->capacity = newcapacity; 
		}
}

void SLInit(SL *head)
{
		head->arr = NULL;
		head->size = head->capacity = 0;
}

void SLPrint(SL *head)
{
	int i = 0;
	for(i=0;i<head->size;i++ )
	{
		printf("%d->",*((head->arr)+i));
	}
	putchar('\n');
}

void SLPushBack(SL *ps,SeqDataType x)//ʵ�ֶ�̬˳����β��
{
	assert(ps);
	checkCapacity(ps);
	ps->arr[ps->size] = x;
	ps->size++;
}

void SLPushFront(SL *ps,SeqDataType x)
{
	assert(ps);
	checkCapacity(ps);
	int i = 0;
	for(i=ps->size;i>0;i--)
	{
		ps->arr[i] =ps->arr[i-1];
	}
	ps->arr[0] = x;
	ps->size++;
}

void SLPopBack(SL *ps)
{
	assert(ps);
	assert(ps->size);
	
	ps->size--;
}

void SLPopFront(SL *ps)
{
	assert(ps);
	assert(ps->size);
	int i = 0;
	for(i=0;i<ps->size-1;i++)
	{
		ps->arr[i] = ps->arr[i+1];
	}
	ps->size--;
}

void SLInsert(SL *ps,int pos,SeqDataType x)
{
	assert(ps);
	assert(pos>=0&&pos<=ps->size);
	
	int i =0;
	for(i=ps->size;i>pos;i--)
	{
		ps->arr[i] = ps->arr[i-1];
	}
	ps->arr[pos] = x;
	ps->size++;
}

void SLErase(SL *ps,int pos)
{
	assert(ps);
	assert(ps->size);
	assert(pos>=0 && pos<ps->size);
		
	int i =0;
	for(i=pos;i<ps->size-1;i++)
	{
		ps->arr[i] = ps->arr[i+1];
	}
	ps->size--;
}

int SLFind(SL *ps,SeqDataType x)
{
	assert(ps);
	int i = 0;
	for(i=0;i<ps->size;i++)
	{
		if(ps->arr[i] ==x)
		{
			return i;
		}
	}
	return -1;
}

void SLDestroy(SL *ps)
{
		assert(ps);
		if(ps->arr)
		{
			free(ps->arr);
		}
		ps->arr = NULL;
		ps->capacity = 0;
		ps->size = 0;
}

int main()
{
		SL ps = {0};
		
		SLInit(&ps);  //��̬����ĳ�ʼ��
	
//	SLPushBack(&ps,11);//β��
//	SLPrint(&ps);//��̬����Ĵ�ӡ
//	SLPushBack(&ps,22);//β��
//	SLPrint(&ps);//��̬����Ĵ�ӡ
//	SLPushBack(&ps,33);//β��
//	SLPrint(&ps);//��̬����Ĵ�ӡ
//	SLPushBack(&ps,44);//β��
//	SLPrint(&ps);//��̬����Ĵ�ӡ
//	SLPushBack(&ps,55);//β��
//	SLPrint(&ps);//��̬����Ĵ�ӡ
//	SLPushBack(NULL,11);//β��
//	SLPrint(&ps);//��̬����Ĵ�ӡ	

		SLPushFront(&ps,11); //ͷ��
		SLPrint(&ps); //11->
		SLPushFront(&ps,22);
		SLPrint(&ps); //22->11->

//		//βɾ
//		SLPopBack(&ps);//22->
//		SLPrint(&ps);
//		SLPopBack(&ps);//22->
//		SLPrint(&ps);
//		SLPopBack(&ps);//22->
//		SLPrint(&ps);
	//ͷɾ
//	SLPopFront(&ps); //11->
//	SLPrint(&ps);
//	SLPopFront(&ps); //
//	SLPrint(&ps);
//	SLPopFront(&ps); //����
//	SLPrint(&ps);
//	
//		SLInsert(&ps,0,44);
//		SLPrint(&ps); //44->22->11->
//		
//		SLInsert(&ps,3,33);
//		SLPrint(&ps); //44->22->11->33->
//		
//		SLInsert(&ps,1,33);
//		SLPrint(&ps); //44->22->11->33->

//		//ɾ��ָ��λ�õ�����
//		SLErase(&ps,1); 
//		SLPrint(&ps);//  22->
//		SLErase(&ps,0); 
//		SLPrint(&ps);// 
//		SLErase(&ps,0); 
//		SLPrint(&ps);// ����
		
		//˳������   //22->11->
//		int ret = SLFind(&ps,33);
//		if(ret<0)
//		{
//			printf("no found\n");	
//		}
//		else
//		{
//			printf("yes is %d\n",ret);	
//		}

		SLDestroy(&ps);
		
	return 0;	
}

*/

//�Ƴ�Ԫ��

//int removeElement(int* arr,int numSize,int val)
//{
//	int i = 0;
//	int j = 0;
//	int count = 0;
//	//ѭ����������
//	for(i=0;i<numSize;i++)
//	{
//		if(arr[i]==val)
//		{	
//			count++;
//			j = i;
//			for(;j<numSize;j++){
//					//arr[i]�����������ǰŲ��һλ
//				arr[j] = arr[j+1];					
//			}				
//		}	
//	}	
//	return numSize-count;
//}

//int removeElement(int* arr,int numSize,int val)
//{
//	int src = 0,dst = 0;
//	while(src<numSize)
//	{
//		if(arr[src]==val)
//		{
//			src++;
//		}else{
//			arr[dst] = arr[src];
//			dst++;
//			src++;
//		}
//	}
//	return dst;
//}
//
//int main()
//{
//	int arr[] = {3,2,2,3,3,3,3,2,2,2};
//	int size = sizeof(arr)/sizeof(arr[0]);
//	int ret = removeElement(arr,size,3);
//	printf("%d ",ret);
//	return 0;	
//}

//void merge(int* nums1,int nums1Size,int m,int* nums2,int nums2Size,int n)
//{
//	int l1 = m-1;   //�����±��ʾ
//	int l2 = n-1;
//	int l3 = m+n-1;
//	
//	while(l2>=0 &&l1>=0)
//	{
//		if(nums1[l1]>nums2[l2])
//		{
//			nums1[l3] = nums1[l1];
//			l1--;
//			l3--;
//		}else
//		{
//			nums1[l3] = nums2[l2];
//			l2--;
//			l3--;
//		}	
//	}
//	while(l2>=0)
//	{
//		nums1[l3] = nums2[l2];
//		l2--;
//		l3--;
//	}	
//}
//int main()
//{
//	int nums1[] = {8,9,10,0,0,0};
//	int nums2[] = {2,5,6};
//	merge(nums1,6,3,nums2,3,3);
//	int i =0;
//	for(i=0;i<6;i++)
//	{
//		printf("%d ",nums1[i]);
//	}
//	return 0;	
//}

