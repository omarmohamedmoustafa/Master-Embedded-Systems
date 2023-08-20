// C program to calculatte factorial of N
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	if(n>=0)
	{
		int i=1;
		int result =1;
		for(i;i<=n;i++)
		{
			result*=i;
		}
		printf("%d",result);
	}
	else
		printf("Factorial of negative number doesn't exist");
	return 0;
}
