#ifndef _FIFO_H_
#define _FIFO_H_



#include"Platform_Types.h"
#include"FIFO_CONFIG.h"

typedef struct{
	data_type count;
	data_type length;
	data_type* ptr_head;
	data_type* ptr_tail;
	data_type* ptr_base;
}FIFO_BUFFER_t;

typedef enum{
	FIFO_NO_ERR,
	FIFO_FULL,
	FIFO_NULL,
	FIFO_EMPTY
}FIFO_BUFFER_STATUS;



FIFO_BUFFER_STATUS FIFO_ENQUEUE (FIFO_BUFFER_t * BUFFER , data_type DATA);
FIFO_BUFFER_STATUS FIFO_DEQUEUE  (FIFO_BUFFER_t * BUFFER , data_type *DATA);
FIFO_BUFFER_STATUS FIFO_INIT (FIFO_BUFFER_t * BUFFER , data_type * HOLDER , uint32_t length);






#endif
