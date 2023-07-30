/*linker script for Cortex M3 mController*/
MEMORY
{
	flash (RX)  :	ORIGIN = 0x08000000 , LENGTH = 128k
	sram  (RWX) :	ORIGIN = 0x20000000 , LENGTH = 20k	
}


SECTIONS
{
	.text :
	{
		*(.vector)
		*(.text)
		*(.rodata)
		_E_TXT_ = . ;
	}> flash
	.data :
	{
		_S_DATA_ = . ;
		*(.data)
		_E_DATA_ = . ;
	}> sram AT> flash
	.bss :
	{
		_S_BSS_ = . ;
		*(.bss)
		_E_BSS_ = . ;
		. = ALIGN(4);
		. = . + 0x1000 ;
		_STACK_TOP_ = .;
	}> sram
}