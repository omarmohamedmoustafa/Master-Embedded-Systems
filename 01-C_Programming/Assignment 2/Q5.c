// C program to check whether character is alphabetic or not
#include<stdio.h>
int main()
{
	char x;
	scanf("%c",&x);
	if((x>='a'&&x<='z') || (x>='A'&&x<='Z'))
	{
		printf("Alphabetic");
	}
	else
	{
		printf("Non-Alphabetic");
	}
	return 0;
}
