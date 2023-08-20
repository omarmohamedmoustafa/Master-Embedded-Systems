//EX4: C Program to Insert an element in an Array
#include<stdio.h>
int main()
{
	int Arr[50];
	int number_Of_elements;
	printf("Enter Number of elements: ");
	fflush(stdout);
	scanf("%d",&number_Of_elements);
	int i;
	for(i=0;i<number_Of_elements;i++)
	{
		scanf("%d",&Arr[i]);
	}
	printf("Enter value of new element: ");
	fflush(stdout);
	int newVal;
	scanf("%d",&newVal);

	printf("Enter location of new element: ");
	fflush(stdout);
	int newIndx;
	scanf("%d",&newIndx);
	for(i=number_Of_elements;i>=newIndx-1;i--)
	{
		Arr[i+1]=Arr[i];
	}
	Arr[newIndx-1]=newVal;
	for(i=0;i<=number_Of_elements;i++)
	{
		printf("%d ",Arr[i]);
	}
return 0;
}
