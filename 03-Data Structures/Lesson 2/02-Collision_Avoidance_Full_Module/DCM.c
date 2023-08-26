#include"DCM.h"
#include"stdio.h"
/*Module private variables*/
static int DCM_SPEED =0;

/*State Pointer to function*/
void  CA_Set_Speed(int speed)
{
	DCM_SPEED= speed;

}

STATE_DEFINE(DCM_Init)
{
	DCM_STATE = DCM_Init;
	DCM_STATE_ptr = STATE_DCM_Busy_Reading;
}
STATE_DEFINE(DCM_Busy_Reading)
{
	DCM_STATE_ptr = STATE_DCM_Busy_Reading;
	printf("Speed = %d",DCM_SPEED);
}
