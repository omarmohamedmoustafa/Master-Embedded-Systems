//EX3: C Program to Find Transpose ofa Matrix
//This program asks user to entera matrix (size of matrix is specified by user) and this program finds the
//transpose of that matrix and displays it.
#include<stdio.h>
int main()
{
	int ArrA[100][100],ArrB[100][100];
	int rows,columns;
	printf("Enter sizes of rows then columns :");
	fflush(stdout);
	scanf("%d %d",&rows,&columns);
	int i,j;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
		{
			printf("Enter item [%d][%d]",i,j);
			fflush(stdout);
			scanf("%d",&ArrA[i][j]);
		}
		}
		printf("\nOriginal Array:\n");
		for(i=0;i<rows;i++)
			{
				for(j=0;j<columns;j++)
				{
					printf("%d\t",ArrA[i][j]);
					fflush(stdout);
				}
				printf("\n");
				fflush(stdout);
			}
		for(i=0;i<rows;i++)
		{
			for(j=0;j<columns;j++)
			{
				ArrB[j][i]=ArrA[i][j];
			}
		}
		printf("\nAfter Transpose:\n");
		fflush(stdout);
		for(i=0;i<columns;i++)
			{
				for(j=0;j<rows;j++)
				{
					printf("%d\t",ArrB[i][j]);
					fflush(stdout);
				}
				printf("\n");
			}
		return 0;
}
