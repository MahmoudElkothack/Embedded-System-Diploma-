/*
 * LIFO.C
 *
 *  Created on: Oct 4, 2021
 *      Author: Mahmoud Elkot
 */

#include "LIFO.h"



LIFO_status LIFO_Add_item(LIFO_BUFF_t* lifo_buffer,int item){

	if(!lifo_buffer->Base || !lifo_buffer->Header)
		return LIFO_null;
	if(lifo_buffer->count == lifo_buffer->length)
		return LIFO_full;
	*(lifo_buffer->Header)= item;
	lifo_buffer->count++;
	lifo_buffer->Header++;
	return LIFO_no_error;

}
LIFO_status LIFO_get_item(LIFO_BUFF_t* lifo_buffer,int* item){
	if(!lifo_buffer->Base || !lifo_buffer->Header)
			return LIFO_null;
	if(lifo_buffer->count == 0)
		return LIFO_empty;
lifo_buffer->Header--;
*item=*(lifo_buffer->Header);
lifo_buffer->count--;

return LIFO_no_error;

 }

LIFO_status LIFO_init(LIFO_BUFF_t* lifo_buffer,int* buffer,int len){
	  if(lifo_buffer == NULL)
		  return LIFO_null;
	  lifo_buffer->Base = buffer;
	  lifo_buffer->Header = buffer;
      lifo_buffer->length = len;
      lifo_buffer->count=0;
      return LIFO_no_error;
 }
//LIFO_status LIFO_is_full(LIFO_BUFF_t* buffer){


// }
