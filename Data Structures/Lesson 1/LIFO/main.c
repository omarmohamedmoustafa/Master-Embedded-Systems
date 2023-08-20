#include"LIFO.h"
#include<stdio.h>
int main()
{
	uint32_t arr[5];
	LIFO_BUFFER_t demo1;
	LIFO_INIT(&demo1,arr,5);
	int i;
	for(i=0;i<7;i++)
	{
		switch(LIFO_PUSH(&demo1,i))
		{
		case LIFO_NO_ERR:
			printf("Item value %d added successfully\n",i);
			break;
		case LIFO_EMPTY:
			printf("Item value %d added successfully\n",i);
			break;
		case LIFO_FULL:
			printf("Can't add item %d because lifo is full\n",i);
			break;
		case LIFO_NULL:
			printf("Can't add item %d because lifo is null\n",i);
			break;
		}

	}
	uint32_t z;
	printf("\n\n");
	fflush(stdout);
	for(i=0;i<7;i++)
	{
		switch(LIFO_POP(&demo1,&z))
		{
		case LIFO_NO_ERR:
			printf("Item value %d popped successfully\n",z);
			break;
		case LIFO_EMPTY:
			printf("No more items can be pooped , LIFO IS EMPTY\n");
			break;
		case LIFO_FULL:
			printf("Can't add item %d because lifo is full\n",z);
			break;
		case LIFO_NULL:
			printf("Can't pop item because lifo is null\n");
			break;
		}
	}
	return 0;
}
