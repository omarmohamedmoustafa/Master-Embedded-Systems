//EX3: C Program to Reverse String Without Using Library Function
//You can only use library function str1en(),To find the length of the string
#include<stdio.h>
int main()
{
	char stringA[100];
	printf("Enter string to reverse manually :");
	fflush(stdout);
	gets(stringA);
	int size =strlen(stringA);
	int i=0,count=0;
	while(stringA[i++]!=0)
	{
		count++;
	}
	char stringB[count+1];
	stringB[count]='\0';
	for(i=0;i<size;i++)
	{
		stringB[count-1]=stringA[i];
		count--;
	}
	printf("%s",stringB);
	return 0;
}
