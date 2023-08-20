// C program to check whether number is positive or negative
#include<stdio.h>
void main(void)
{
	signed int x;
	scanf("%d",&x);
	if(x>0)
		printf("Positive");
	else if(x<0)
		printf("Negative");
	else
		printf("Zero");
  return 0;
}
