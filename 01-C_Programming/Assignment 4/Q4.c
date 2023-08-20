/*
 * EX4: C program to Calculate the Power of a Number Using Recursion
 */
#include"stdio.h"
int powerUsingRecursion(int n , int pow);
int main ()
{
	int base,pow;
	printf("Enter base number :");
	fflush(stdout);
	scanf("%d",&base);
	printf("Enter pow number(Positive Integer) :");
	fflush(stdout);
	scanf("%d",&pow);
	int res = powerUsingRecursion(base,pow);
	printf("%d power %d equals %d ",3,3,res);
	return 0;
}
int powerUsingRecursion(int n , int pow)
{
	static int res =1;
	if(pow==0)
		return res;
	else
	{
		res*=n;
		powerUsingRecursion(n,--pow);
	}
	return res;
}
