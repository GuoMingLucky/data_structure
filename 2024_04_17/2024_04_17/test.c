
#include "SList.h"
#include "file.h"
#include"_Time.h"

void test02()
{
	SLNode SL;
	struct SLNode* pcur = &SL;
	SLNodeInit(&pcur, 'a');
	SLNodeInsert(&pcur, 'b', 'a');//a->b
	SLNodeInsert(&pcur, 'c', 'a');
	SLNodeInsert(&pcur, 'd', 'a');
	SLNodeInsert(&pcur, 'e', 'a');
	SLNodePrint(pcur);   //a->e->d->c->b->
	//fscanf(stdout,"%d",i);     //从文件中获取文本信息
	//sprintf(pFile,"a->e->d->c->b->");  
	//saveContext(pcur);

	printf("\n");                     //字符g找不到了
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
	//	SLNodePrint(pcur);  //失败
	printf("\n");
	SLChangeData(&pcur, 'e', 'a');
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

//	SLChangeData(&pcur, 'b', 'c');   //找不到b了
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
