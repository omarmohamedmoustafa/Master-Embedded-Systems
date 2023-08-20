/*Write a program in C to print all the alphabets using a pointer.*/
#include<stdio.h>
int main()
{
	char* alpha_ptr;
	char alphabet[27];
	alpha_ptr = alphabet;
	int i;
	for(i=0;i<26;i++)
	{
		*alpha_ptr = i + 'A';
		printf("%c  ",*alpha_ptr);
		alpha_ptr++;
	}
	return 0;
}
