#ifndef _DB_H_
#define _DB_H_

#include<stdio.h>
#include<stdlib.h>
typedef struct{
	unsigned int ID;
	char NAME[50];
	double TOTAL_MARKS;
}SDATA;
struct STUDENT
{
	SDATA SDATA;
	struct STUDENT* P_NXT_STUDENT;
};


void	ADD_STUDENT();
void	DELETE_STUDENT();
void	DISPLAY_STUDENTS();
void	DELETE_ALL();




#endif
