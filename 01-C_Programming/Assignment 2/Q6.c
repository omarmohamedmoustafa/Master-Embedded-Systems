// C program to calculate sum of natural number from 1 up to user enterd value N
#include<stdio.h>
int main ()
{
	int x;
	scanf("%d",&x);
	int i=1;
	int sum =0;
	for(i;i<=x;i++)
	{
		sum+=i;
	}
	printf("%d",sum);
	return 0;
}
