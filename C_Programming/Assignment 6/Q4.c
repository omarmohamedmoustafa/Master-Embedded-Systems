/*Write a program in C to print the elements of an array in reverse order.*/
#include<stdio.h>
int main()
{
	int size;
	printf("Enter size of array:\n");fflush(stdout);fflush(stdin);
	scanf("%d",&size);
	int arr[size];
	int i;
	printf("Input 5 number of elements in the array :\n");fflush(stdout);fflush(stdin);
	for(i=0;i<size;i++)
	{
		printf("Element %d: ",i+1);fflush(stdout);fflush(stdin);
		scanf("%d",&arr[i]);
	}
	printf("The elements of array in reverse order are :\n");
	int* p_int=&arr[size-1];
	for(i=0;i<size;i++)
	{
		printf("Element %d : %d\n",size-i,*(p_int--));
	}
	return 0;
}
