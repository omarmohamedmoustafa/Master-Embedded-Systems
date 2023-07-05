//EX2: C Program to Find the Length of a String
//You can use standard library function strlen() to find the length of a string
//but, this program computes the length of a string manually without using
//strlen() funtion.
#include<stdio.h>
int main()
{
	char string[100];
	printf("enter string to let me compute its length WITHOUT strlen() :");
	fflush(stdout);
	gets(string);
	int count=0;
	int i=0;
	while(string[i++]!=0)
	{
		count++;
	}
	printf("String (%s) length is (%d)",string,count);
  return 0;
}
