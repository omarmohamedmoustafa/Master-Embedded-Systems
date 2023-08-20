#include"FIFO.h"
#include<stdio.h>
int main()
{
	data_type arr[5];
	FIFO_BUFFER_t demo1;
	FIFO_INIT(&demo1,arr,5);
	data_type i;
	for(i=0;i<7;i++)
	{
		switch(FIFO_ENQUEUE(&demo1,i))
		{
		case FIFO_NO_ERR:
			printf("Item value %d added successfully\n",i);
			break;
		case FIFO_EMPTY:
			printf("Item value %d added successfully\n",i);
			break;
		case FIFO_FULL:
			printf("Can't add item %d because FIFO is full\n",i);
			break;
		case FIFO_NULL:
			printf("Can't add item %d because FIFO is null\n",i);
			break;
		}
	}
	data_type z=0;
	printf("\n\n");
	fflush(stdout);
	for(i=0;i<7;i++)
	{
		switch(FIFO_DEQUEUE(&demo1,&z))
		{
		case FIFO_NO_ERR:
			printf("Item value %d popped successfully\n",z);
			break;
		case FIFO_EMPTY:
			printf("No more items can be popped , FIFO IS EMPTY\n");
			break;
		case FIFO_FULL:
			printf("Can't add item %d because FIFO is full\n",z);
			break;
		case FIFO_NULL:
			printf("Can't pop item because FIFO is null\n");
			break;
		}
	}
	return 0;
}
