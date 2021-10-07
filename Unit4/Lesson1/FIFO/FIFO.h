/*
 * FIFO.h
 *
 *  Created on: Oct 4, 2021
 *      Author: ALBORAQ
 */
#include <stdio.h>
#include<stdint.h>
#ifndef FIFO_H_
#define FIFO_H_
#define element_type uint8_t

#define width 5

element_type uart_buff [width];

typedef struct{
unsigned int length;
unsigned int count;
element_type* tail;
element_type* base;
element_type* head;
}fifo_buf_t;

typedef enum {
FIFO_no_error,
FIFO_full,
FIFO_empty,
FIFO_null

}FIFO_STATUS;

//FIFO API
FIFO_STATUS FIFO_init(fifo_buf_t* fifo , element_type* buff,uint32_t length);
FIFO_STATUS FIFO_enqueue(fifo_buf_t* fifo , element_type item);
FIFO_STATUS FIFO_dequeue(fifo_buf_t* fifo , element_type* item);
FIFO_STATUS  FIFO_is_full(fifo_buf_t* fifo);
void  FIFO_print(fifo_buf_t* fifo );



#endif /* FIFO_H_ */
