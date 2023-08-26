#ifndef _CA_H_
#define _CA_H_
#include "state.h"

/*Enumeration for my module states*/

enum{
	CA_Waiting_S,
	CA_Driving_S
}CA_STATE;

/*Prototypes declaration for the module states*/
STATE_DEFINE(CA_Waiting);
STATE_DEFINE(CA_Driving);

extern void (* CA_STATE_ptr)();









#endif
