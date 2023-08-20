/*
 * EX2: C program to Calculate Factorial of a Number Using Recursion
*/
#include"stdio.h"
int factorial(int x);
int main()
{
	int x;
	printf("Enter a number to calculate it's recursion :");
	fflush(stdout);
	scanf("%d",&x);
	if(x>=0)
	{
		int res = factorial(x);
		printf("Factorial of %d is %d",x,res);
	}
	else
		printf("Negative numbers can't have factorials");
	return 0;
}
int factorial(int x)
{
	static int res=1;
	if(x<=1)
		return 1;
	else
	{
		res*=x;
		factorial(--x);
		return res;
	}
}
