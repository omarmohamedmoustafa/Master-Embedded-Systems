/*c function to count the max number of ones between two zeros*/
#include<stdio.h>
int temp;
int arr[100]={0},i=0;
void decToBin(int num);
int main()
{
	int tempMax=0,max=0;
	int j;
	int num;
	printf("Enter a number to get number of ones in it's binary representation: \n");
	fflush(stdout);
	scanf("%d",&num);
	decToBin(num);
	for(j=0;j<100;j++)
	{
		/*printf("%d",arr[j]);*/
		if(arr[j]==0)
		{
			while(arr[j+1]==1)
				{
					tempMax++;
					j++;
				}
		}
		if(tempMax>max)
			max=tempMax;
		else
			tempMax=0;
	}
	printf("%d",max);
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
