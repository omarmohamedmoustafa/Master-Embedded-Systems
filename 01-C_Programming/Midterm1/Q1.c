/*c function to take a number and sum all digits?*/
#include<stdio.h>
int main ()
{
	int num;
	printf("Enter number to sum it's digits: \n");
	fflush(stdout);
	scanf("%d",&num);
	int sum =0;
	while(num!=0)
	{
		sum+=num%10;
		num/=10;
	}
	printf("%d\n",sum);
	return 0;
}
