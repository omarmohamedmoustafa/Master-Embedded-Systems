



#include<stdio.h>
#include"Platform_Types.h"
extern v_uint32_t _E_TXT_;
extern v_uint32_t _S_DATA_;
extern v_uint32_t _E_DATA_;
extern v_uint32_t _S_BSS_;
extern v_uint32_t _E_BSS_;
extern v_uint32_t _STACK_TOP_;
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
