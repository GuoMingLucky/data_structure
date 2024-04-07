#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int STDataType;
//栈底层用的是静态顺序表
typedef struct Stack
{
	STDataType* _arr;
	int top;           //有效个数
	int capacity;	      //空间大下
}Stack;

void StackInit(Stack* ps)
{
	ps->_arr =NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_arr);
	ps->_arr = NULL;
	ps->capacity = ps->top = 0;
}
//入栈
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	int newcapacity = 0;
	if (ps->top == ps->capacity)
	{
		newcapacity = ps->capacity == 0 ? 4:2 * newcapacity;
		STDataType* ptmp = realloc(ps->_arr, sizeof(STDataType) * newcapacity);
		if (ptmp == NULL)
		{
			perror("realloc failed ");
			exit(1);
		}
		ps->_arr = ptmp;
		ps->capacity = newcapacity;
	}
	ps->_arr[ps->top] = x;
	ps->top++;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	//free(ps->_arr[ps->top]);
	ps->top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	return ps->_arr[ps->top-1];
}

int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top > 0 ? 0 : 1;
}

int main()
{
	Stack st;
	StackInit(&st);

	StackPush(&st, 11);
	StackPush(&st, 22);
	StackPush(&st, 33);
	StackPush(&st, 44);
	// 44 
	STDataType ret = StackTop(&st);
	printf("%d ",ret);
	StackPop(&st);
	printf("\n");
	// 11 22 33 
	while (!StackEmpty(&st)) 
	{
		ret = StackTop(&st);
		printf("%d ",ret);
		StackPop(&st);
	}
	//33 22 11 
	printf("\n");
	
	StackDestroy(&st);

	return 0;
}