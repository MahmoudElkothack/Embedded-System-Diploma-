/*
 * CA.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Mahmoud elkot
 */

#include "US.h"
//variables
int US_distance=0;


int get_distance_rand(int l,int r,int count);
 void (*US_state)();

 STATE_define(US_busy){
	 //state name
 US_state_id=US_busy;
	 //state action

	 //state check
   US_distance= get_distance_rand(45,55,1);
 //(distance <= threshold)? (ca_state= STATE(CA_waiting)) :(ca_state= STATE(CA_driving));
   printf("ca_waiting state: distance=%d\n",US_distance);
   US_set_distance(US_distance);

   US_state = STATE(US_busy);

 }

 void US_init(){

	 //init US_driver
 }


 int get_distance_rand(int l,int r,int count){
	 int i;
	 for (i = 0; i < count; i++) {
		int rand_num=(rand()%(r-l+1))+1;
	   return rand_num;
	 }



 }

