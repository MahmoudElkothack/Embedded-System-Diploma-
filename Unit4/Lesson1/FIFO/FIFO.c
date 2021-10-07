/*

 * FIFO.c
 *
 *  Created on: Oct 4, 2021
 *      Author: ALBORAQ
 */

#include "FIFO.h"


FIFO_STATUS FIFO_init(fifo_buf_t* fifo , element_type* buff,uint32_t length){

	if(buff == NULL)
		return FIFO_null;
	fifo->length=length;
	fifo->base=buff;
	fifo->tail=buff;
	fifo->head=buff;
	fifo->count=0;
	return FIFO_no_error;

}
FIFO_STATUS FIFO_enqueue(fifo_buf_t* fifo , element_type item){
	if(!fifo->base || !fifo->head || !fifo->tail )
        return FIFO_null;

	if(FIFO_is_full(fifo) ==FIFO_full)
		return FIFO_full;
	 *(fifo->head) = item;
      fifo->count++;
      if(fifo->head == fifo->base + fifo->length* sizeof(element_type) )
    	  fifo->head = fifo->base;

      else
    	  fifo->head++;
  return FIFO_no_error;
}
FIFO_STATUS FIFO_dequeue(fifo_buf_t* fifo , element_type* item){

	if(!fifo->base || !fifo->head || !fifo->tail )
	 return FIFO_null;
	if(fifo->count ==0)
	return FIFO_empty;
	*item =*(fifo->tail);
	fifo->count--;
	  if(fifo->tail == fifo->base + fifo->length* sizeof(element_type) )
	    	  fifo->tail = fifo->base;

	      else
	    	  fifo->tail++;
	  return FIFO_no_error;

}

FIFO_STATUS  FIFO_is_full(fifo_buf_t* fifo){
	if(!fifo->base || !fifo->head || !fifo->tail )
	        return FIFO_null;
	if(fifo->count == fifo->length)
		return FIFO_full;
	return FIFO_no_error;
}

void  FIFO_print(fifo_buf_t* fifo ){
	element_type* temp;
	int i;
	if(fifo->count ==0)
		printf("\nfifo is empty");
	else{
		temp = fifo->tail;
		for(i=0;i<fifo->count;i++)
		{
			printf("\t%x\n",*temp);
			temp++;
		}
	}

}
