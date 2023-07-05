//EX 2 C Program to Calculate Average Using Arrays
//This program takes n number of element from user(where, n is specified by user), stores data in an array
//and calculates the average of those numbers.
#include<stdio.h>
int main ()
{
	int number_of_entries;
	printf("Enter number of entries :");
	fflush(stdout);
	scanf("%d",&number_of_entries);
	int i;
	float Arr[100];Dummy size
	if(number_of_entries<=100)
	{
		for(i=0;i<number_of_entries;i++)
		{
			printf("Enter Number %d: ",i+1);
			fflush(stdout);
			scanf("%f",&Arr[i]);
		}
	}
	double sum;
	for(i=0;i<number_of_entries;i++)
	{
		sum+=Arr[i];
	}
	sum/=number_of_entries;
	printf("Average = %.2lf",sum);
  return 0;
}
