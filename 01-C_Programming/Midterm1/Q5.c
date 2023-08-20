/*c function to reverse digits in number?*/
#include<stdio.h>
int main()
{
	int num;
	printf("Enter number to reverse it's digits :\n");
	fflush(stdout);
	scanf("%d",&num);
	char stringInt[100];
	itoa(num,stringInt,10);
	int i,size=strlen(stringInt),temp,tempSize;
	tempSize=size;
	for(i=0;i<size/2;i++)
	{
		temp=stringInt[i];
		stringInt[i]=stringInt[tempSize-1];
		stringInt[tempSize-1]=temp;
		tempSize--;
	}
	printf("%s",stringInt);
	return 0;
}
