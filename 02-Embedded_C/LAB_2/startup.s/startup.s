/* Startup file for cortex M3 Boards*/

/* within cortex M3,
 * We have got from the datsheet that entry point of Processor
 * is on address 0x08000000
 * we shall put the SP value in this location
 * to allow the processor to set SP with our address in
 * location 0x08000000
 *
 *
 * The next locations should hold the vector table as
 * stated in the datasheet
 * 
 *
 */
 
/* Using .word to inform that we need to store the addresses */ 
.section .vector
.word 0x20001000		/* The initial address of stack pointer*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/
.word _reset_handler	/* The Symbol (Address) of the reset handler section*/

.thumb_func
.section .text
_reset_handler:
	bl main
	b _end

_end:
	b _end

_vector_handler:
	b _reset_handler