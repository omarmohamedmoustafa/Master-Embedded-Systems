#ifndef _ALARM_ACTUATOR_H_
#define _ALARM_ACTUATOR_H_

#include"state.h"
#include "driver.h"


enum{
	alarmActuator_OFF,
	alarmActuator_ON
}alarmActuator_State;


STATE_DEFINE(alarmActuator_OFF);
STATE_DEFINE(alarmActuator_ON);
void alarmActuator_init();
void(*alarmActuator_state_ptr)();




#endif
