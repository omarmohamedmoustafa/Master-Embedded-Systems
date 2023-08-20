#include"Platform_Types.h"
#include"main.h"
/* Defining the Tiva C base registers adresses*/
#define SYSCTL_BASE	(uint32_t)0x400FE000
#define GPIO_F_BASE	(uint32_t)0x40025000

typedef union{
	v_uint32_t ALL_PINS_DATA;
	struct{
		v_uint32_t DATA_PIN_0:1;
		v_uint32_t DATA_PIN_1:1;
		v_uint32_t DATA_PIN_2:1;
		v_uint32_t DATA_PIN_3:1;
		v_uint32_t DATA_PIN_4:1;
		v_uint32_t DATA_PIN_5:1;
		v_uint32_t DATA_PIN_6:1;
		v_uint32_t DATA_PIN_7:1;
		v_uint32_t DATA_PIN_8:1;
		v_uint32_t DATA_PIN_9:1;
		v_uint32_t DATA_PIN_10:1;
		v_uint32_t DATA_PIN_11:1;
		v_uint32_t DATA_PIN_12:1;
		v_uint32_t DATA_PIN_13:1;
		v_uint32_t DATA_PIN_14:1;
		v_uint32_t DATA_PIN_15:1;
		v_uint32_t DATA_PIN_16:1;
		v_uint32_t DATA_PIN_17:1;
		v_uint32_t DATA_PIN_18:1;
		v_uint32_t DATA_PIN_19:1;
		v_uint32_t DATA_PIN_20:1;
		v_uint32_t DATA_PIN_21:1;
		v_uint32_t DATA_PIN_22:1;
		v_uint32_t DATA_PIN_23:1;
		v_uint32_t DATA_PIN_24:1;
		v_uint32_t DATA_PIN_25:1;
		v_uint32_t DATA_PIN_26:1;
		v_uint32_t DATA_PIN_27:1;
		v_uint32_t DATA_PIN_28:1;
		v_uint32_t DATA_PIN_29:1;
		v_uint32_t DATA_PIN_30:1;
		v_uint32_t DATA_PIN_31:1;
	}DATA_PINS;
}GPIO_PORT_F_DATA_R;
typedef union{
	v_uint32_t DIR_ALL_PINS;
	struct{
		v_uint32_t DIR_PIN_0:1;
		v_uint32_t DIR_PIN_1:1;
		v_uint32_t DIR_PIN_2:1;
		v_uint32_t DIR_PIN_3:1;
		v_uint32_t DIR_PIN_4:1;
		v_uint32_t DIR_PIN_5:1;
		v_uint32_t DIR_PIN_6:1;
		v_uint32_t DIR_PIN_7:1;
		v_uint32_t DIR_PIN_8:1;
		v_uint32_t DIR_PIN_9:1;
		v_uint32_t DIR_PIN_10:1;
		v_uint32_t DIR_PIN_11:1;
		v_uint32_t DIR_PIN_12:1;
		v_uint32_t DIR_PIN_13:1;
		v_uint32_t DIR_PIN_14:1;
		v_uint32_t DIR_PIN_15:1;
		v_uint32_t DIR_PIN_16:1;
		v_uint32_t DIR_PIN_17:1;
		v_uint32_t DIR_PIN_18:1;
		v_uint32_t DIR_PIN_19:1;
		v_uint32_t DIR_PIN_20:1;
		v_uint32_t DIR_PIN_21:1;
		v_uint32_t DIR_PIN_22:1;
		v_uint32_t DIR_PIN_23:1;
		v_uint32_t DIR_PIN_24:1;
		v_uint32_t DIR_PIN_25:1;
		v_uint32_t DIR_PIN_26:1;
		v_uint32_t DIR_PIN_27:1;
		v_uint32_t DIR_PIN_28:1;
		v_uint32_t DIR_PIN_29:1;
		v_uint32_t DIR_PIN_30:1;
		v_uint32_t DIR_PIN_31:1;
	}DIR_PINS;
}GPIO_PORT_F_DIR_R;
typedef union{
	v_uint32_t DEN_ALL_PINS;
	struct{
		v_uint32_t DEN_PIN_0:1;
		v_uint32_t DEN_PIN_1:1;
		v_uint32_t DEN_PIN_2:1;
		v_uint32_t DEN_PIN_3:1;
		v_uint32_t DEN_PIN_4:1;
		v_uint32_t DEN_PIN_5:1;
		v_uint32_t DEN_PIN_6:1;
		v_uint32_t DEN_PIN_7:1;
		v_uint32_t DEN_PIN_8:1;
		v_uint32_t DEN_PIN_9:1;
		v_uint32_t DEN_PIN_10:1;
		v_uint32_t DEN_PIN_11:1;
		v_uint32_t DEN_PIN_12:1;
		v_uint32_t DEN_PIN_13:1;
		v_uint32_t DEN_PIN_14:1;
		v_uint32_t DEN_PIN_15:1;
		v_uint32_t DEN_PIN_16:1;
		v_uint32_t DEN_PIN_17:1;
		v_uint32_t DEN_PIN_18:1;
		v_uint32_t DEN_PIN_19:1;
		v_uint32_t DEN_PIN_20:1;
		v_uint32_t DEN_PIN_21:1;
		v_uint32_t DEN_PIN_22:1;
		v_uint32_t DEN_PIN_23:1;
		v_uint32_t DEN_PIN_24:1;
		v_uint32_t DEN_PIN_25:1;
		v_uint32_t DEN_PIN_26:1;
		v_uint32_t DEN_PIN_27:1;
		v_uint32_t DEN_PIN_28:1;
		v_uint32_t DEN_PIN_29:1;
		v_uint32_t DEN_PIN_30:1;
		v_uint32_t DEN_PIN_31:1;
	}DEN_PINS;
}GPIO_PORT_F_DEN_R;
/*Define pointer to union holding adress of real register in memory*/
volatile GPIO_PORT_F_DIR_R*  PORT_F_DIR_R  = ((volatile GPIO_PORT_F_DIR_R* )(GPIO_F_BASE + 0x400));
volatile GPIO_PORT_F_DEN_R*  PORT_F_DEN_R = ((volatile GPIO_PORT_F_DEN_R* )(GPIO_F_BASE + 0x51C));
volatile GPIO_PORT_F_DATA_R* PORT_F_DATA_R = ((volatile GPIO_PORT_F_DATA_R*)(GPIO_F_BASE + 0x3FC));

#define SYSCTL_RCGC2_R *((uint32_t*)(SYSCTL_BASE + 0x108))

void main ()
{
	/*Enable GPIO PORT And make some delay*/
	v_uint32_t i;
	SYSCTL_RCGC2_R =0x20;
	for(i=0;i<1000;i++);
	PORT_F_DIR_R->DIR_PINS.DIR_PIN_3 =1;
	PORT_F_DEN_R->DEN_PINS.DEN_PIN_3 =1;
	while(1)
	{
		PORT_F_DATA_R->DATA_PINS.DATA_PIN_3 =1;
		for(i=0;i<50000;i++);
		PORT_F_DATA_R->DATA_PINS.DATA_PIN_3 = 0;
		for(i=0;i<50000;i++);
	}
}