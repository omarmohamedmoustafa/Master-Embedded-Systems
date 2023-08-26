#include"CA.h"
#include"stdio.h"


/*Module private variables*/
 int CA_SPEED =0;
 int CA_DISTANCE =0;
 int CA_THRESHOLD =50;



/*State Pointer to function*/

void (* CA_STATE_ptr)();

void US_Send_Distance(int distance)
{
	CA_DISTANCE = distance;
	(CA_DISTANCE > CA_THRESHOLD)? (CA_STATE_ptr = STATE_CA_Driving):(CA_STATE_ptr = STATE_CA_Waiting);
}


STATE_DEFINE(CA_Waiting)
{
	/*State Name*/
	CA_STATE = CA_Waiting_S;
	/*State Action*/
	CA_SPEED = 0 ;
	CA_Set_Speed(CA_SPEED);
	/*Event Check and transition*/
	fflush(stdout);fflush(stdin);printf("CA_State = Waiting\tCA_Speed = %d\tCA_Distance = %d\n",CA_SPEED,CA_DISTANCE);
}

STATE_DEFINE(CA_Driving)
{
	/*State Name*/
	CA_STATE = CA_Driving_S;

	/*State Action*/
	CA_SPEED = 20 ;
	CA_Set_Speed(CA_SPEED);
	fflush(stdout);fflush(stdin);printf("CA_State = Driving\tCA_Speed = %d\tCA_Distance = %d\n",CA_SPEED,CA_DISTANCE);
}
