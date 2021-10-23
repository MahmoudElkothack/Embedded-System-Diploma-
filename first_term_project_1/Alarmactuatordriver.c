/*
 * Alarmactuatordriver.c
 *
 *  Created on: Oct 22, 2021
 *      Author: mahmoud elkot
 */
#include "Alarmactuatordriver.h"
void (*alarm_actuator_states)();
 enum{

	alarm_on,
	alarm_off,
	waiting

}id_alarm_actuator;
void inti (){
	// init driver

}

STATE_define(alarm_on){
//	printf("alarm_on_driver");
	id_alarm_actuator = alarm_on;
	Set_Alarm_actuator(1);
	alarm_actuator_states=STATE(waiting);
}
STATE_define(alarm_off){
	//printf("alarm_off_driver");
	id_alarm_actuator = alarm_off;
   Set_Alarm_actuator(0);
   alarm_actuator_states=STATE(waiting);
}
STATE_define(waiting){
	//printf("waiting_driver");
	id_alarm_actuator=waiting;

}

void start_alarm(){
	alarm_actuator_states=STATE(alarm_on);
}
void stop_alarm(){
	alarm_actuator_states=STATE(alarm_off);

}
