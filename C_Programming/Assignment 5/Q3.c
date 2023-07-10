/*EX5: C Program to find area of a circle, passing arguments to macros*/
#include<stdio.h>
#define PI 22.0/7.0
int main()
{
	int radius;
	printf("Enter the radius: ");fflush(stdout);fflush(stdin);
	scanf("%d",&radius);
	printf("Area =%lf",PI*radius*radius);fflush(stdout);fflush(stdin);
	return 0;
}
