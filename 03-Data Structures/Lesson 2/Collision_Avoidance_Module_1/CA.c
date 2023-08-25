#include"CA.h"
#include"stdio.h"


/*Module private variables*/
static int CA_SPEED =0;
static int CA_DISTANCE =0;
static int CA_THRESHOLD =50;



/*State Pointer to function*/

void (* CA_STATE_ptr)();
int randDistance(int low, int high, int outputsNumber);


STATE_DEFINE(CA_Waiting)
{
	/*State Name*/
	CA_STATE = CA_Waiting_S;

	/*State Action*/
	CA_SPEED = 0 ;
	CA_DISTANCE = randDistance(45,55,1);
	/*Event Check and transition*/
	(CA_DISTANCE > CA_THRESHOLD)? (CA_STATE_ptr = STATE_CA_Driving):(CA_STATE_ptr = STATE_CA_Waiting);
	fflush(stdout);fflush(stdin);printf("CA_State = Waiting\tCA_Speed = %d\tCA_Distance = %d\n",CA_SPEED,CA_DISTANCE);
}

STATE_DEFINE(CA_Driving)
{
	/*State Name*/
	CA_STATE = CA_Driving_S;

	/*State Action*/
	CA_SPEED = 20 ;
	CA_DISTANCE = randDistance(45,55,1);
	/*Event Check and transition*/
	(CA_DISTANCE > CA_THRESHOLD)? (CA_STATE_ptr = STATE_CA_Driving):(CA_STATE_ptr = STATE_CA_Waiting);
	fflush(stdout);fflush(stdin);printf("CA_State = Driving\tCA_Speed = %d\tCA_Distance = %d\n",CA_SPEED,CA_DISTANCE);
}

int randDistance(int low, int high, int outputsNumber)
{
	int distance=0;
	int i;
	for(i=0;i<outputsNumber;i++)
	{
		distance = (rand()%(high - low + 1)) +low;
		return distance;
	}
	return 0;
}
