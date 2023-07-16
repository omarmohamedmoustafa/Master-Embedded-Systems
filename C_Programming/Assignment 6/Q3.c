/*Write a program in C to print a string in reverse using a pointer*/
#include<stdio.h>
int main()
{
	char str[100];
	printf("Enter string to reverse by pointer:\n");fflush(stdout);fflush(stdin);
	gets(str);
	char* p_str_f=str;
	int i=0;
	char* p_str_l;
	int j=0;
	while(str[++i])
		{
			p_str_l=&str[i];
			j++;
		}
	char temp;
	i=0;
	if((j%2))
		j--;
	while(--j)
		{
			temp = *(p_str_f+i);
			*(p_str_f+i)=*(p_str_l-i);
			*(p_str_l-i)=temp;
			i++;
		}
	i=0;
	while(str[i])
	{
		printf("%c",str[i++]);
	}
	return 0;
}
