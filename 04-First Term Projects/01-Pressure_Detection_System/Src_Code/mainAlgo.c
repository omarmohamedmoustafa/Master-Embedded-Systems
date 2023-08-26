#include"mainAlgo.h"
#include"driver.h"
int mAlgoPressureVal = 0;
int threshold = 20;
int highPressureDetected()
{
	if(getPressureVal()>=20)
		return 1;
	else return 0;
}
