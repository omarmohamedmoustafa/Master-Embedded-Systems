#include"alarmActuator.h"
#include"mainAlgo.h"
void alarmActuator_init()
{
	alarmActuator_state_ptr = STATE_alarmActuator_OFF;
}
void set_alarm()
{
	Set_Alarm_actuator(0);
}

void clr_alarm()
{
	Set_Alarm_actuator(1);
}

STATE_DEFINE(alarmActuator_OFF)
{
	alarmActuator_State = alarmActuator_OFF;
	if(highPressureDetected())
		alarmActuator_state_ptr = STATE_alarmActuator_ON;
	else
		alarmActuator_state_ptr = STATE_alarmActuator_OFF;
	clr_alarm();

}
STATE_DEFINE(alarmActuator_ON)
{
	alarmActuator_State =alarmActuator_ON;
	set_alarm();
	Delay(600000);
	clr_alarm();
	Delay(600000);
	alarmActuator_state_ptr = STATE_alarmActuator_OFF;
}
