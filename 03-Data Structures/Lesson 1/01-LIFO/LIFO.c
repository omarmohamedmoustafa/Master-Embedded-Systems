/*
 ============================================================================
 Name        : LIFO.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include"LIFO.h"

LIFO_BUFFER_STATUS LIFO_PUSH (LIFO_BUFFER_t * BUFFER , uint32_t DATA)
{
	if(!BUFFER->ptr_tail || !BUFFER->ptr_head)
		return LIFO_NULL;
	if(BUFFER->count == BUFFER->length)
		return LIFO_FULL;
	*(BUFFER->ptr_head) = DATA;
	BUFFER->ptr_head++;
	BUFFER->count++;
	return LIFO_NO_ERR;
}
LIFO_BUFFER_STATUS LIFO_POP  (LIFO_BUFFER_t * BUFFER , uint32_t *DATA)
{
	if(!BUFFER->ptr_tail || !BUFFER->ptr_head)
		return LIFO_NULL;
	if(BUFFER->count == 0)
		return LIFO_EMPTY;
	BUFFER->ptr_head--;
	*DATA = *(BUFFER->ptr_head);
	BUFFER->count--;
	return LIFO_NO_ERR;
}
LIFO_BUFFER_STATUS LIFO_INIT (LIFO_BUFFER_t * BUFFER , uint32_t * HOLDER , uint32_t length)
{
	if(!HOLDER)
		return LIFO_NULL;
	BUFFER->ptr_head = HOLDER;
	BUFFER->ptr_tail = HOLDER;
	BUFFER->length = length;
	BUFFER->count = 0;
	return LIFO_NO_ERR;
}



