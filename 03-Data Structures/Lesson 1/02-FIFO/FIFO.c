#include"FIFO.h"
FIFO_BUFFER_STATUS FIFO_ENQUEUE (FIFO_BUFFER_t * BUFFER , data_type DATA)
{
	if(! BUFFER->ptr_base || !BUFFER->ptr_head || !BUFFER->ptr_tail)
		return FIFO_NULL;
	if(BUFFER->count == BUFFER->length)
		return FIFO_FULL;
	*(BUFFER->ptr_head)= DATA;
	BUFFER->count ++;
	/*Circular queue implementation*/
	if(BUFFER->ptr_head == (BUFFER->ptr_base + BUFFER->length * sizeof(data_type)))
		BUFFER->ptr_head = BUFFER->ptr_base;
	else
		BUFFER->ptr_head++;
	return FIFO_NO_ERR;
}
FIFO_BUFFER_STATUS FIFO_DEQUEUE  (FIFO_BUFFER_t * BUFFER , data_type *DATA)
{
	if(! BUFFER->ptr_base || !BUFFER->ptr_head || !BUFFER->ptr_tail)
		return FIFO_NULL;
	if(BUFFER->count == 0)
		return FIFO_EMPTY;
	*DATA = *(BUFFER->ptr_tail);
	BUFFER->count --;
	if(BUFFER->ptr_tail == (BUFFER->ptr_base + (BUFFER->length * sizeof(data_type))))
		BUFFER->ptr_tail = BUFFER->ptr_base;
	else
		BUFFER->ptr_tail++;
	return FIFO_NO_ERR;

}
FIFO_BUFFER_STATUS FIFO_INIT (FIFO_BUFFER_t * BUFFER , data_type * HOLDER , uint32_t length)
{
	if(!HOLDER)
		return FIFO_NULL;
	BUFFER->ptr_base = HOLDER;
	BUFFER->ptr_head = HOLDER;
	BUFFER->ptr_tail = HOLDER;
	BUFFER->count = 0;
	BUFFER->length =length;

	return FIFO_NO_ERR;
}

