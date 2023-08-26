#ifndef _STATE_H_
#define _STATE_H_

/*
 * Automatic state definition
	for text replacement
 */

#define STATE_DEFINE(_STATE_FUN_) void STATE_##_STATE_FUN_()

extern int randDistance(int low, int high, int outputsNumber);

void US_Send_Distance(int distance);
void  CA_Set_Speed(int speed);

#endif
