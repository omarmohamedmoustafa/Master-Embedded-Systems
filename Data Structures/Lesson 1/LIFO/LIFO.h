/*HEADER_GUARD*/
#ifndef _LIFO_H_
#define _LIFO_H_

#include"Platform_Types.h"
/* naming convention for my APIs:
// each api start by the name of the DS
// each lifo buffer will have some attributes
// we will need to track length, size, ptr_head, ptr_base
 */

typedef struct{
	uint32_t count;
	uint32_t length;
	uint32_t* ptr_head;
	uint32_t* ptr_tail;
}LIFO_BUFFER_t;

typedef enum{
	LIFO_NO_ERR,
	LIFO_FULL,
	LIFO_NULL,
	LIFO_EMPTY
}LIFO_BUFFER_STATUS;


LIFO_BUFFER_STATUS LIFO_PUSH (LIFO_BUFFER_t * BUFFER , uint32_t DATA);
LIFO_BUFFER_STATUS LIFO_POP  (LIFO_BUFFER_t * BUFFER , uint32_t *DATA);
LIFO_BUFFER_STATUS LIFO_INIT (LIFO_BUFFER_t * BUFFER , uint32_t * HOLDER , uint32_t length);




#endif
