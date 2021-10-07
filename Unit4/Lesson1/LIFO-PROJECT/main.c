/*
 * main.c
 *
 *  Created on: Oct 4, 2021
 *      Author: Mamoud Elkot
 */

#include "LIFO.h"

unsigned int buffer1[5];
int main(){
    int i,temp;
    LIFO_BUFF_t uart_lifo, i2c_lifo;
    LIFO_init(&uart_lifo,buffer1,5);
    unsigned int* buffer2 =( unsigned int*)malloc(sizeof(unsigned int)*5);  //4*5 =20
    LIFO_init(&i2c_lifo,buffer2,5);

    for(i=0;i<5;i++){
  if(LIFO_Add_item(&uart_lifo,i) == LIFO_no_error)
    printf("Uart add item:%d\n",i);
    }
    for(i=0;i<5;i++){
       if(LIFO_get_item(&uart_lifo,&temp) == LIFO_no_error)
       printf("Uart get value:%d\n",temp);
       }
}


