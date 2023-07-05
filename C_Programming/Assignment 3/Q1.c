/*EX 1 Write a C program to find sum of two matrix of order 2*2 using multidimensional arrays where, elements of matrix are entered by user.*/
#include<stdio.h>
int main()
{
	float Arr1[2][2],Arr2[2][2];
	int i;
	int j;
	printf("Enter Elements of 1st Array\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("A[%d][%d] ->",i,j);
			fflush(stdout);
			scanf("%f",&Arr1[i][j]);
		}
	}
	printf("Enter Elements of 2nd Array\n");
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				printf("B[%d][%d] ->",i,j);
				fflush(stdout);
				scanf("%f",&Arr2[i][j]);
			}
		}
		printf("The sum of two arrays =\n");
			for(i=0;i<2;i++)
			{
				for(j=0;j<2;j++)
				{
					printf("%.2f\t",Arr1[i][j]+=Arr2[i][j]);
				}
				printf("\n");
			}
	return 0;
}
