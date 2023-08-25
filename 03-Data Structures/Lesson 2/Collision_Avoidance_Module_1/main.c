#include"CA.h"

void setup()
{
	/*init drivers, interrupts*/
	CA_STATE_ptr = STATE_CA_Waiting;
}

int main()
{
	setup();
	while(1)
	{
		CA_STATE_ptr();
	}
	return 0;
}
