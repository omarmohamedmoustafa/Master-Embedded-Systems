#include"Platform_Types.h"

/*
 * within previous lab, we used to define a global array which would be put 
 * in .data section but we forced it to be put in .vector section with 
 * __attribute__(setion(".vector")) pre-defined directive
 * also we calculated the Stack_Top address from the Linker_Script.ld file
 * in this lab we shall usse a newer approach withot Stack_Top symbbol in Linker_Script
 * the approach is to define an array of 256 element, each 32 bit wide
 * so we end up having 1024 byte of .bss section
*/

extern v_uint32_t _E_TXT_;
extern v_uint32_t _S_DATA_;
extern v_uint32_t _E_DATA_;
extern v_uint32_t _S_BSS_;
extern v_uint32_t _E_BSS_;
/*extern v_uint32_t _STACK_TOP_;*/
extern void main();
void _RESET_HANDLER_();
void _DEFAULT_HANDLER_();
void _HARD_FAULT_HANDLER_() 	__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _NMI_HANDLER_() 			__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _MEM_MANAGE_HANDLER_() 	__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _BUS_FAULT_HANDLER_() 		__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _USAGE_FAULT_HANDLER_() 	__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _RESERVED_() 				__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _SV_CALL_HANDLER_() 		__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _DEBUG_MONITOR_HANDLER_() 	__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _PEND_SV_HANDLER_() 		__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _SYSTICK_HANDLER_() 		__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _WWDG_HANDLER_() 			__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _PVD_HANDLER_() 			__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _TAMPER_HANDLER_() 		__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _RTC_HANDLER_() 			__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _FLASH_HANDLER_() 			__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _RCC_HANDLER_() 			__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _EXTI0_HANDLER_() 			__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _EXTI1_HANDLER_() 			__attribute__((weak,alias("_DEFAULT_HANDLER_")));
void _EXTI2_HANDLER_() 			__attribute__((weak,alias("_DEFAULT_HANDLER_")));

/*
v_uint32_t vectors[] __attribute__((section(".vector"))) ={
	(uint32_t) &_STACK_TOP_,
	(uint32_t) _RESET_HANDLER_,
	(uint32_t) _NMI_HANDLER_,
	(uint32_t) _HARD_FAULT_HANDLER_,
	(uint32_t) _MEM_MANAGE_HANDLER_,
	(uint32_t) _BUS_FAULT_HANDLER_,
	(uint32_t) _USAGE_FAULT_HANDLER_,
	(uint32_t) _RESERVED_,
	(uint32_t) _SV_CALL_HANDLER_,
	(uint32_t) _DEBUG_MONITOR_HANDLER_,
	(uint32_t) _RESERVED_,
	(uint32_t) _PEND_SV_HANDLER_,
	(uint32_t) _SYSTICK_HANDLER_,
	(uint32_t) _WWDG_HANDLER_,
	(uint32_t) _PVD_HANDLER_,
	(uint32_t) _TAMPER_HANDLER_,
	(uint32_t) _RTC_HANDLER_,
	(uint32_t) _FLASH_HANDLER_,
	(uint32_t) _RCC_HANDLER_,
	(uint32_t) _EXTI0_HANDLER_,
	(uint32_t) _EXTI1_HANDLER_,
	(uint32_t) _EXTI2_HANDLER_
};
*/

v_uint32_t Stack [256]={0}; /* uninitialized global array : will be in .bss*/

/* 
Now we need to define an array of pointers
 * point to function take any parameters, return void
 * 
 void (*Arr_Ptr_Fun[])()={
		//
		// here we shall put the same contents of the array we made in lab1
		// 1- Stack Pointer value
		// 2- Reset Handler
		// OTHER ISR Handlers Addresses
 };
 */
void (* const Arr_Ptr_Fun[])() __attribute__((section(".vector")))=
{
	(void (*)()) ((uint32_t)Stack + sizeof(Stack)),
	_RESET_HANDLER_,
	_NMI_HANDLER_,
	_HARD_FAULT_HANDLER_,
	_MEM_MANAGE_HANDLER_,
	_BUS_FAULT_HANDLER_,
	_USAGE_FAULT_HANDLER_,
	_RESERVED_,
	_SV_CALL_HANDLER_,
	_DEBUG_MONITOR_HANDLER_,
	_RESERVED_,
	_PEND_SV_HANDLER_,
	_SYSTICK_HANDLER_,
	_WWDG_HANDLER_,
	_PVD_HANDLER_,
	_TAMPER_HANDLER_,
	_RTC_HANDLER_,
	_FLASH_HANDLER_,
	_RCC_HANDLER_,
	_EXTI0_HANDLER_,
	_EXTI1_HANDLER_,
	_EXTI2_HANDLER_
};



void _RESET_HANDLER_ ()
{
	v_uint32_t _DATA_SIZE_ = (uint8_t*)&_E_DATA_ - (uint8_t*)&_S_DATA_;
	v_uint8_t* _P_DATA_SRC_ = (uint8_t*)&_E_TXT_;
	v_uint8_t* _P_DATA_DST_ = (uint8_t*)&_S_DATA_;
	int i;
	for(i=0;i<_DATA_SIZE_;i++)
	{
		*((uint8_t*)_P_DATA_DST_++) = *((uint8_t*)_P_DATA_SRC_++);
	}
	v_uint32_t _BSS_SIZE_ = (uint8_t*)&_E_BSS_ - (uint8_t*)&_S_BSS_;
	v_uint8_t* _P_BSS_DST_ = (uint8_t*)&_S_BSS_;
	for(i=0;i<_BSS_SIZE_;i++)
	{
		*((uint8_t*)_P_BSS_DST_++) = (uint8_t)0;
	}
	main();
}

void _DEFAULT_HANDLER_ ()
{
	_RESET_HANDLER_();
}
