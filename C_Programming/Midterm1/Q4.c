/*c function to reverse digits in number?*/
#include<stdio.h>
int main()
{
	int arr[99]={0};
	int number;
	printf("Enter number to reverse: \n");
	fflush(stdout);
	scanf("%d",&number);
	int i=0;
	while(number!=0)
	{
		arr[i++]=number%10;
		number/=10;
	}
	printf("Reversed number: \n");
	fflush(stdout);
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("%d",size);
	while(size--)
	{
		printf("%d",arr[i++]);
		fflush(stdout);
	}
	return 0;
}
