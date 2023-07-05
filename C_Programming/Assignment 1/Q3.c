/EX4:Write C Program to Multiply two Floating Point Numbers

#include<stdio.h>
int main()
{
	float s;
	float d;
	printf("Enter the two numbers:");
	fflush(stdout);
	scanf("%f\n",&s);
	scanf("%f",&d);
	printf("Product = %f",s*d);
	return 0;
}
