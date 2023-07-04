#include"stdio.h"
/*
 * EX1: Prime Numbers Between two Intervals by Making User-defined Function
 */
/*
void prime(int x,int y);
int main ()
{
	int x,y;
	printf("Enter two numbers to print prime between them :");
	fflush(stdout);
	scanf("%d%d",&x,&y);
	prime(x,y);
	return 0;
}

void prime(int x, int y)
{
	int i,j;
	printf("Prime numbers from %d to %d are:\n",x,y);
	fflush(stdout);
	for(i=x;i<=y;i++)
	{
		for(j=2;j<i;j++)
		{
			if((i%j) == 0)
				break;
			else
				continue;
		}
		if(j==i)
		{
			printf("%d\t",i);
			fflush(stdout);
		}
	}
}
 */

/*
 * EX2: C program to Calculate Factorial of a Number Using Recursion


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
 */

/*
 * EX3: C program to Reverse a Sentence Using Recursion

void reverseStatement(char string[],int size);
int main ()
{
	char string[999];
	printf("Enter a string to reverse by recursion :");
	fflush(stdout);
	gets(string);
	int size = strlen(string);
	reverseStatement(string,size);
	return 0;
}
void reverseStatement(char string[],int size)
{
	if(size>0)
	{
		int i=0;
		while(string[i++]!=0 && i<strlen(string));
		printf("%c",string[i-1]);
		string[i-1]=0;
		size--;
		reverseStatement(string,size);
	}
}
 */




/*
 * EX4: C program to Calculate the Power of a Number Using Recursion
 
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
*/
