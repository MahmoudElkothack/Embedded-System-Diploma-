/*
 * LIFO.h
 *
 *  Created on: Oct 4, 2021
 *      Author: Mahmoud Elkot
 */

#ifndef LIFO_H_
#define LIFO_H_
#include<stdio.h>


typedef struct{
unsigned int length;
unsigned int* Base;
unsigned int* Header;
unsigned int count;

 }LIFO_BUFF_t; ///data type LIFO

 typedef enum{
	 LIFO_no_error,
	 LIFO_full,
	 LIFO_not_full,
	 LIFO_empty,
	 LIFO_not_empty,
	 LIFO_null,
 }LIFO_status; //status of data structure

 ///API

 LIFO_status LIFO_Add_item(LIFO_BUFF_t* ,int);
 LIFO_status LIFO_get_item(LIFO_BUFF_t*,int*);
 LIFO_status LIFO_init(LIFO_BUFF_t*,int*,int);
 //LIFO_status LIFO_is_full(LIFO_BUFF_t*);



#endif /* LIFO_H_ */
