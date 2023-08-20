/*
 * main.c
 *
 *  Created on: Jul 10, 2023
 *      Author: Omar_
 */
/*EXI: C Program to Store Information(name, roll and marks) of a Student
Using Structure*/

#include<stdio.h>
struct s_studentData{
	char name [50];
	int roll	  ;
	int marks [8 ];
};
int main()
{
	printf("Enter number of students you want to enter: \n");
	fflush(stdout);
	int sz,i,j;
	scanf("%d",&sz);
	struct s_studentData arrayOfStudents[sz];
	for(i=0;i<sz;i++)
	{
		printf("Enter student %d name :\n",i+1);
		fflush(stdout);fflush(stdin);
		gets(arrayOfStudents[i].name);
		printf("Enter student %d Marks :\n",i+1);
		fflush(stdout);fflush(stdin);
		for(j=0;j<8;j++)
		{
			scanf("%d",&arrayOfStudents[i].marks[j]);
			fflush(stdout);fflush(stdin);
		}
		printf("Enter student %d roll :\n",i+1);
		fflush(stdout);fflush(stdin);
		scanf("%d",&arrayOfStudents[i].roll);
		printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");
		fflush(stdout);fflush(stdin);
	}
	printf("Displaying students data:\n");
	fflush(stdout);fflush(stdin);
	for(i=0;i<sz;i++)
		{
			printf("Student number %d\n",i+1);
			fflush(stdout);fflush(stdin);
			printf("NAME: %s\n",arrayOfStudents[i].name);
			fflush(stdout);fflush(stdin);
			printf("MARKS:\n");
			fflush(stdout);fflush(stdin);
			for(j=0;j<8;j++)
			{
				printf("%d\t",arrayOfStudents[i].marks[j]);
				fflush(stdout);fflush(stdin);
			}
			printf("\nROLL:\n");
			fflush(stdout);fflush(stdin);
			printf("%d\n",arrayOfStudents[i].roll);
			fflush(stdout);fflush(stdin);
			printf("=======================================\n");
		}
	return 0;
}
