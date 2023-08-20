//Write C program to check Vowel or Constant
#include<stdio.h>
int main ()
{
	char letter;
	scanf("%c",&letter);
	if(letter == 'a' ||letter == 'A'||letter == 'e'||letter == 'E'||letter == 'i'||letter == 'I'||letter == 'o'||letter == 'O'||letter == 'u'||letter == 'U')
		printf("Vowel");
	else
		printf("Constant");
	return 0;
}
