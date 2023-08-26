#ifndef _US_H_
#define _US_H_
#include"state.h"
enum{
	US_Init,
	US_Busy_Reading
}US_STATE;

STATE_DEFINE(US_Init);
STATE_DEFINE(US_Busy_Reading);

void (*US_State_Ptr)();





#endif
