
#include "SList.h"
#include "_Time.h"

static FILE* pFile;

void get_time()
{
	time_t timep;
	time(&timep);
	fprintf(pFile, "%s", ctime(&timep));
	//Wed Apr 10 14:36:57 2024
}

void saveContext(SLNode* pcur)
{
	pFile = fopen("my_file.txt", "w+");
	if (pFile == NULL)
	{
		perror("open my_file.txt failed");
		exit(1);
	}
	else
	{
		while (pcur)
		{
			fwrite(&(pcur->data), sizeof(pcur->data), 1, pFile);
			pcur = pcur->next;
		}
		get_time();

		fclose(pFile);
	}
}
void getContext(SLNode** pcur)
{
	assert(pcur);
	pFile = fopen("my_file.txt", "r+");

	SLNode info;
	while (fread(&info, sizeof(info), 1, pFile))
	{
		SLNodeInsertBack(pcur, info.data);
		//printf("获取数据成功\n");
	}
	printf("\n获取数据成功\n");
	get_time();
	fclose(pFile);
}