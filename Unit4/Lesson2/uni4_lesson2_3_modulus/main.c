/*
 * main.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Mahmoud elkot
 */

#include "CA.h"
#include "US.h"
#include "DC.h"

void setup(){

	US_state= STATE(US_busy);
	ca_state = STATE(CA_waiting);
	DC_state = STATE(DC_idle);
}

int main(){
int w=0;
	setup();
	while(1){
		US_state();
        ca_state();
       DC_state();
     for(w=0;w<10000;w++);
	}
}
