#include"queue.h"

int main() 
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	//1 2 3 
	printf("%d ",QueueFront(&q));
	QueuePop(&q);
	printf("\n");

	QueuePush(&q, 4);
	QueuePush(&q, 5);
	//2 3 4 5 
	while (!QueueEmpty(&q)) 
	{
		printf("%d ",QueueFront(&q));
		QueuePop(&q);   //必须要有出队列，不然会陷入死循环中
	}
	printf("\n");
	QueueDestroy(&q);

	return 0;
}