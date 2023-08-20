//EX5: C Program to Search an element in Array
#include<stdio.h>
int main()
{
	int number_of_elements;
	int Arr[100];
	printf("Enter number of elements :");
	fflush(stdout);
	scanf("%d",&number_of_elements);
	int i;
	for(i=0;i<number_of_elements;i++)
	{
		printf("enter number index %d :",i+1);
		fflush(stdout);
		scanf("%d",&Arr[i]);
	}
	printf("Enter the element to search for : ");
	fflush(stdout);
	int searched_item;
	scanf("%d",&searched_item);
	for(i=0;i<number_of_elements;i++)
	{
		if(Arr[i]==searched_item)
			{
				printf("Found at location :%d",i+1);
				break;
			}
	}
	if(i==number_of_elements)
		printf("Element not found.. :( ");
  return 0;
}
