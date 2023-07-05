//EX2: Write C Program to Print a Integer Entered by a User
#include<stdio.h>
int main()

{
	int x;
	printf("Enter the number to display:\n");
	fflush(stdout);
	scanf("%d",&x);
	printf("Number is : %d",x);
	return 0;
}
