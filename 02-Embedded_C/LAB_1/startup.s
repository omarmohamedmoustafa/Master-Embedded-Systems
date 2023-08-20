.globl reset

reset:
		ldr sp, =stack_top
		bl main
end_:	b end_