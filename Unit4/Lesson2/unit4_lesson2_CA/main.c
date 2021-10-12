/*
 * main.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Mahmoud elkot
 */

#include "CA.h"
void setup(){

	ca_state = STATE(CA_waiting);
}

int main(){
int w=0;
	setup();
	while(1){
		ca_state();
     for(w=0;w<10000;w++);
	}
}
