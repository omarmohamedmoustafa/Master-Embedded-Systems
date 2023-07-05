// Exl: C Program to Find the Frequency of Characters in a String
#include<stdio.h>
int main()
{
	char string[100];
	printf("Enter the string :");
	fflush(stdout);
	gets(string);
	printf("Enter the character to find frequency :");
	fflush(stdout);
	char character;
	scanf("%c",&character);
	int i=0,count=0;
	while(string[i]!=0)
	{
		if(string[i]==character)
			count++;
		i++;
	}
	printf("Frequency of Character (%c) in string (%s) is (%d",character,string,count);
  return 0;
}
