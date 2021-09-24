#include "Uart.h"
unsigned char data[100]="learn_in_depth:ELKOT";
unsigned int f;
void main(void){

Uart_Send_string(data);


}
