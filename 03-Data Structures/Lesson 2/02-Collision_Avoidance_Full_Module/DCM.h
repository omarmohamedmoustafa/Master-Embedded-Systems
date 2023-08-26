#ifndef _DCM_H_
#define _DCM_H_
#include"state.h"
enum{
	DCM_Init,
	DCM_Busy_Reading
}DCM_STATE;

STATE_DEFINE(DCM_Init);
STATE_DEFINE(DCM_Busy_Reading);

 void (* DCM_STATE_ptr)();





#endif
