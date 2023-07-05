/*
 * EX3: C program to Reverse a Sentence Using Recursion
*/
#include"stdio.h"
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

