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
void US_set_distance(int d){

	distance=d;
 (distance <= threshold)? (ca_state= STATE(CA_waiting)) :(ca_state= STATE(CA_driving));
printf("US--------distance=%d-------CA\n",distance);

}
int get_distance_rand(int l,int r,int count);
 void (*ca_state)();

 STATE_define(CA_waiting){
	 //state name
 CA_state_id=CA_waiting;
	 //state action
   speed=0;
	 //state check
motor_set(speed);
printf("ca_waiting state: distance=%d  ,  speed=%d\n",distance,speed);

 }
 STATE_define(CA_driving){

	 //state name
 CA_state_id=CA_driving;
	 //state action
   speed=30;
	 //state check

 printf("ca_waiting state: distance=%d  ,  speed=%d\n",distance,speed);
motor_set(speed);
 }


