/*
 * handlepointer.c
 *
 *  Created on: Sep 13, 2021
 *      Author: mahmoud elkot
 */

#include<stdio.h>
/*struct try_1{
	unsigned  z:5;
	unsigned   x:5;
	unsigned    c:6;
}bit;*/
unsigned long int (*avg())[3]{
	static unsigned long int arr[]={1,2,3};
	return &arr;
}


int main(){
	unsigned long int (*ptr)[3];

	ptr=avg();

	printf("%d",'g'-'o');


	return 0;

}
