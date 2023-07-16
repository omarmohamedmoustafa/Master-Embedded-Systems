#include<stdio.h>
int main()
{
	int m;
	m=29;
	int* ptr_int=& m;
	printf("Address of m = 0x%p\n",ptr_int);
	printf("Value of m = %d\n",*ptr_int);

	int* ab = ptr_int;
	printf("Address of ab = 0x%p\n",ab);
	printf("Value of ab = %d\n",*ab);

	m=34;
	printf("Address of ab = 0x%p\n",ab);
	printf("Value of ab = %d\n",*ab);
	
	*ab =7;
	printf("Address of ab = 0x%p\n",ab);
	printf("Value of ab = %d\n",*ab);
	return 0;
}
