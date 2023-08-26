#include"US.h"

static int DISTANCE=0;
int randDistance(int low, int high, int outputsNumber);

STATE_DEFINE(US_Init)
{
	US_STATE=US_Init;
	DISTANCE =0;
	US_State_Ptr=STATE_US_Busy_Reading;
}
STATE_DEFINE(US_Busy_Reading)
{
	US_STATE = US_Busy_Reading;
	DISTANCE = randDistance(45,55,1);
	US_Send_Distance(DISTANCE);
	US_State_Ptr = STATE_US_Busy_Reading;
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
