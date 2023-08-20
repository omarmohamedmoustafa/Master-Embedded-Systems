/*c function to take an integer number and calculate it's square root?*/
#include<stdio.h>
int main()
{
	int x;
	printf("Enter a number to calculate it's square root: \n");
	fflush(stdout);
	scanf("%d",&x);
	float y=sqrt(x);
	printf("Result =: %f",y);
	return 0;
}
