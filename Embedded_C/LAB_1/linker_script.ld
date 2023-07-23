ENTRY(reset)

MEMORY
{
	mem (rwx) : ORIGIN =0x0 , LENGTH = 64M
}

SECTIONS
{
	. = 0x10000 ;
	.startup . :
	{
		startup.o(.text)
	}> mem
	.text :
	{
		*(.text)
	}> mem
	.data :
	{
		*(.data)
	}> mem
	.rodata :
	{
		*(.rodata)
	}> mem
	.bss :
	{
		*(.bss)
	}> mem
	. = . + 0x1000 ;
	stack_top = . ;
}