#include <stdint.h>
#include <stdio.h>
#include "driver.h"
#include "alarmActuator.h"
#include "mainAlgo.h"
int main (){
	GPIO_INITIALIZATION();
	alarmActuator_init();
	while (1)
	{
		alarmActuator_state_ptr();
	}

}
