/*
 * main.c
 *
 *  Created on: Oct 4, 2021
 *      Author: ALBORAQ
 */
#include "FIFO.h"
int main(){

	  fifo_buf_t FIFO_Uart;
	  element_type i,temp;
      if(FIFO_init(&FIFO_Uart,&uart_buff,5) == FIFO_no_error)
         printf("fifo---Done\n");
      for(i=0;i<7;i++){
    	 if(FIFO_enqueue(&FIFO_Uart,i) == FIFO_no_error)
    		 printf("success to insert\n");
    	 else
    		 printf("failed to insert\n");

      }
      FIFO_print(&FIFO_Uart);


      if(FIFO_dequeue(&FIFO_Uart,&temp) == FIFO_no_error)
    	  printf("fifo dequeue:%x\n",temp);
      if(FIFO_dequeue(&FIFO_Uart,&temp) == FIFO_no_error)
         	  printf("fifo dequeue:%x\n",temp);
      FIFO_print(&FIFO_Uart);
}



