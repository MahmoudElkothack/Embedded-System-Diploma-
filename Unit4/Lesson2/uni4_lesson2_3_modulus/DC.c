/*
 * CA.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Mahmoud elkot
 */

#include "DC.h"
//variables
int DC_speed=0;



 void (*DC_state)();

 void DC_init(){

	 //init pwd
 }

 void motor_set(int s){

	 DC_speed = s;

	 DC_state=STATE(DC_busy);
	 printf("CA-----------SPEED=%d----------DC\n",DC_speed);
 }

 STATE_define(DC_idle){
	 //state name
 DC_state_id = DC_idel;
	 //state action
   //speed=0;
	 //state check
  // distance= get_distance_rand(45,55,1);
 //(distance <= threshold)? (ca_state= STATE(CA_waiting)) :(ca_state= STATE(CA_driving));
printf("DC_idle state speed=%d\n",DC_speed);

 }
 STATE_define(DC_busy){

	 //state name
 DC_state_id = DC_busy;
	 //state action
   //speed=30;
	 //state check
 //  distance= get_distance_rand(45,55,1);
 //(distance <= threshold)? (ca_state= STATE(CA_waiting)) :(ca_state= STATE(CA_driving));

 printf("DC_busy state:speed=%d\n",DC_speed);
 DC_state=STATE(DC_idle);
 }



