#include"CA.h"
#include"DCM.h"
#include"US.h"
void setup()
{
	/*init drivers, interrupts*/
	US_State_Ptr=STATE_US_Init;
	CA_STATE_ptr = STATE_CA_Waiting;
	DCM_STATE_ptr=STATE_DCM_Init;

}

int main()
{
	setup();
	while(1)
	{
		CA_STATE_ptr();
		US_State_Ptr();
		DCM_STATE_ptr();
	}
	return 0;
}
