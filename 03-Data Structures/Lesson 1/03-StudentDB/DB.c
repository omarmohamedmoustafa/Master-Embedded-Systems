#include"DB.h"

static int id=0;

struct STUDENT* GP_First = NULL;


void	ADD_STUDENT()
{
	int i=0;
	char temp[50];
	struct STUDENT * PNEW_STUDENT = (struct STUDENT*) malloc (sizeof( struct STUDENT));
	/*Fill Student Data*/
	PNEW_STUDENT->SDATA.ID=id;
	fflush(stdout);fflush(stdin);printf("Enter new student Name:\n");
	gets(PNEW_STUDENT->SDATA.NAME);
	fflush(stdout);fflush(stdin);printf("Enter new student Total Marks:\n");
	PNEW_STUDENT->SDATA.TOTAL_MARKS=atof(gets(temp));
	if(!GP_First)/*Case 1 : first student to add*/
	{
		GP_First=PNEW_STUDENT;
		PNEW_STUDENT->P_NXT_STUDENT=NULL;
		fflush(stdout);fflush(stdin);printf("\nFirst Student ID %d Added successfully\n\n",id);
	}
	else /* add at the end*/
	{
		struct STUDENT * temp = GP_First;
		while(temp->P_NXT_STUDENT)
			temp = temp->P_NXT_STUDENT;
		temp->P_NXT_STUDENT =PNEW_STUDENT ;
		PNEW_STUDENT->P_NXT_STUDENT=NULL;
		fflush(stdout);fflush(stdin);printf("\nNew Student ID :%d Added successfully\n\n",id);
	}
	id++;
}
void	DELETE_STUDENT()
{
    char temp[50];
    fflush(stdout);fflush(stdin);printf("\nEnter student ID you want to delete:\n");
    gets(temp);
	/* We need two pointers to trace the linked list to find the needed user*/
	struct STUDENT* P_Prev_Student;
	struct STUDENT* P_Current_Student;
	P_Prev_Student=NULL;
	P_Current_Student = GP_First;
	/*Case 1 : EMPTY LIST*/
	if(!GP_First)
	{
		fflush(stdout);fflush(stdin);printf("\nNothing to delete, List is empty\n\n");
		return;
	}
	else
	{
		/*list has some nodes*/
		/* ------- 	 -------  ------- 	 -------
		 * |	 |	 |	   |  |		|	|		|
		 * |  X  |	 |	O  |  |	O   |	|	O	|
		 * |  	 |	 |	   |  |		|	|		|
		 * -------   -------  -------	---------
		 * to remove X
		 */
		while(P_Current_Student)
		{
			if(P_Current_Student->SDATA.ID == atoi(temp))
			{
				if(P_Prev_Student == NULL)
					GP_First=P_Current_Student->P_NXT_STUDENT;
				else
				{
					P_Prev_Student->P_NXT_STUDENT = P_Current_Student->P_NXT_STUDENT;
				}
				free(P_Current_Student);
				fflush(stdout);fflush(stdin);printf("\nStudent whose ID = %d was successfully deleted..\n\n",atoi(temp));
				return;
			}
			P_Prev_Student=P_Current_Student;
			P_Current_Student = P_Current_Student->P_NXT_STUDENT;
		}
		fflush(stdout);fflush(stdin);printf("\nStudent with ID = %d is not found, check again..\n\n",atoi(temp));
		return;

	}

}
void	DISPLAY_STUDENTS()
{
	struct STUDENT* itterator=(struct STUDENT*)malloc(sizeof(struct STUDENT));
	itterator = GP_First;
	if(itterator==NULL)
	printf("\nNo students in the Database, you shall add some first\n\n");
	while(itterator)
	{
		fflush(stdout);fflush(stdin);printf("\nStudent Name:%s\nStudent ID:%d\nStudent Total Marks:%f\n",itterator->SDATA.NAME,itterator->SDATA.ID,itterator->SDATA.TOTAL_MARKS);
		itterator=itterator->P_NXT_STUDENT;
	}
	fflush(stdout);fflush(stdin);printf("\n");
}
void	DELETE_ALL()
{
	struct STUDENT* itterator1=(struct STUDENT*)malloc(sizeof(struct STUDENT));
	struct STUDENT* itterator2=(struct STUDENT*)malloc(sizeof(struct STUDENT));
	itterator1 = GP_First;
	itterator2 = NULL;
	GP_First=NULL;
	if(!itterator1->P_NXT_STUDENT)
	{
		free(itterator1);

	}
	while(itterator1->P_NXT_STUDENT)
	{
		itterator2=itterator1;
		free(itterator2);
		itterator1=itterator1->P_NXT_STUDENT;
	}
	fflush(stdout);fflush(stdin);printf("\nAll students were deleted :O\n");

}
