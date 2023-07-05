/*c function to count number of ones in binary number?*/
#include<stdio.h>
int temp;
int arr[100]={0},i=0;
int main()
{
	void decToBin(int num);
	int num;
	printf("Enter a number to get number of ones in it's binary representation: \n");
	fflush(stdout);
	scanf("%d",&num);
	decToBin(num);
	int j,result;
	for(j=0;j<100;j++)
	{
		if(arr[j]==1)
		result++;
	}
	printf("Number of ones in %d is %d",num,result);
	return 0;
}
void decToBin(int num)
{
	if(num!=0)
	{
		temp =num%2;
		num/=2;
		arr[i++]=temp;
		decToBin(num);
	}
}
