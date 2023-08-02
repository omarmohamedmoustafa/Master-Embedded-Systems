/*linker script for TIVA C*/
MEMORY
{
	flash (RX)  :	ORIGIN = 0x00000000 , LENGTH = 512M
	sram  (RWX) :	ORIGIN = 0x20000000 , LENGTH = 512M	
}


SECTIONS
{
	.text :
	{
		*(.vector)
		*(.text)
		*(.rodata)
		. = ALIGN(4);
		_E_TXT_ = . ;
	}> flash
	.data :
	{
		_S_DATA_ = . ;
		*(.data)
		. = ALIGN(4);
		_E_DATA_ = . ;
	}> sram AT> flash
	.bss :
	{
		_S_BSS_ = . ;
		*(.bss)
		. = ALIGN(4);
		_E_BSS_ = . ;
	}> sram
}