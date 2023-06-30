/*
 * main.c
 *
 *  Created on: Jun 30, 2023
 *      Author: Omar_
 */

#include<stdio.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EX 1 Write a C program to find sum of two matrix of order 2*2 using multidimensional arrays where,
//elements of matrix are entered by user.
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EX 2 C Program to Calculate Average Using Arrays
//This program takes n number of element from user(where, n is specified by user), stores data in an array
//and calculates the average of those numbers.
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EX3: C Program to Find Transpose ofa Matrix
//This program asks user to entera matrix (size of matrix is specified by user) and this program finds the
//transpose of that matrix and displays it.
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EX4: C Program to Insert an element in an Array
int main()
{
	int Arr[50];
	int number_Of_elements;
	printf("Enter Number of elements: ");
	fflush(stdout);
	scanf("%d",&number_Of_elements);
	int i;
	for(i=0;i<number_Of_elements;i++)
	{
		scanf("%d",&Arr[i]);
	}
	printf("Enter value of new element: ");
	fflush(stdout);
	int newVal;
	scanf("%d",&newVal);

	printf("Enter location of new element: ");
	fflush(stdout);
	int newIndx;
	scanf("%d",&newIndx);
	for(i=number_Of_elements;i>=newIndx-1;i--)
	{
		Arr[i+1]=Arr[i];
	}
	Arr[newIndx-1]=newVal;
	for(i=0;i<=number_Of_elements;i++)
	{
		printf("%d ",Arr[i]);
	}
return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EX5: C Program to Search an element in Array
int main()
{
	int number_of_elements;
	int Arr[100];
	printf("Enter number of elements :");
	fflush(stdout);
	scanf("%d",&number_of_elements);
	int i;
	for(i=0;i<number_of_elements;i++)
	{
		printf("enter number index %d :",i+1);
		fflush(stdout);
		scanf("%d",&Arr[i]);
	}
	printf("Enter the element to search for : ");
	fflush(stdout);
	int searched_item;
	scanf("%d",&searched_item);
	for(i=0;i<number_of_elements;i++)
	{
		if(Arr[i]==searched_item)
			{
				printf("Found at location :%d",i+1);
				break;
			}
	}
	if(i==number_of_elements)
		printf("Element not found.. :( ");

}



/*			Strings				*/



// Exl: C Program to Find the Frequency of Characters in a String

int main()
{
	char string[100];
	printf("Enter the string :");
	fflush(stdout);
	gets(string);
	printf("Enter the character to find frequency :");
	fflush(stdout);
	char character;
	scanf("%c",&character);
	int i=0,count=0;
	while(string[i]!=0)
	{
		if(string[i]==character)
			count++;
		i++;
	}
	printf("Frequency of Character (%c) in string (%s) is (%d",character,string,count);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EX2: C Program to Find the Length of a String
//You can use standard library function strlen() to find the length of a string
//but, this program computes the length of a string manually without using
//strlen() funtion.
int main()
{
	char string[100];
	printf("enter string to let me compute its length WITHOUT strlen() :");
	fflush(stdout);
	gets(string);
	int count=0;
	int i=0;
	while(string[i++]!=0)
	{
		count++;
	}
	printf("String (%s) length is (%d)",string,count);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EX3: C Program to Reverse String Without Using Library Function
//You can only use library function str1en(),To find the length of the string
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

