//Write C program to check whether a number is even or odd

#include<stdio.h>

int main ()
{
	int num;
	scanf("%d",&num);
	if(num%2)
		printf("Odd");
	else
		printf("Even");
	return 0;
}
