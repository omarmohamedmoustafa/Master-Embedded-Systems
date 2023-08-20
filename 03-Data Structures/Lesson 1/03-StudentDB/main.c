#include"DB.h"
int main()
{

	char choice[1];
	while(1)
	{
	    int i=0;
		printf("============================================\nCHOOSE ONE OF THE FOLLOWING OPTIONS:\n1: Add new student\n2: Delete Student\n3: View Students\n4: Delete All\nq: Exit Program\n============================================\n\n");
        scanf("%c",&choice);
        if(choice[0]=='q')
		{
			printf("Program Ended...");
			break;
		}
		else
		{
			switch(atoi(choice))
			{
			case 1:
			    ADD_STUDENT();
				break;
            case 2:
			    DELETE_STUDENT();
				break;
			case 3:
			    DISPLAY_STUDENTS();
				break;
            case 4:
			    DELETE_ALL();
				break;
            default:
                printf("Wrong choice, please try again");
                break;
			}
		}
	}




	return 0;
}
