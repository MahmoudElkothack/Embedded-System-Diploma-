/*
 * CA.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Mahmoud elkot
 */

#include "CA.h"
//variables
int speed=0;
int distance=0;
int threshold=50;

int get_distance_rand(int l,int r,int count);
 void (*ca_state)();

 STATE_define(CA_waiting){
	 //state name
 CA_state_id=CA_waiting;
	 //state action
   speed=0;
	 //state check
   distance= get_distance_rand(45,55,1);
 (distance <= threshold)? (ca_state= STATE(CA_waiting)) :(ca_state= STATE(CA_driving));
printf("ca_waiting state: distance=%d  ,  speed=%d\n",distance,speed);

 }
 STATE_define(CA_driving){

	 //state name
 CA_state_id=CA_driving;
	 //state action
   speed=30;
	 //state check
   distance= get_distance_rand(45,55,1);
 (distance <= threshold)? (ca_state= STATE(CA_waiting)) :(ca_state= STATE(CA_driving));

 printf("ca_waiting state: distance=%d  ,  speed=%d\n",distance,speed);

 }

 int get_distance_rand(int l,int r,int count){
	 int i;
	 for (i = 0; i < count; i++) {
		int rand_num=(rand()%(r-l+1))+1;
	   return rand_num;
	 }



 }

