/*
 * AlarmMonitor.c
 *
 *  Created on: Oct 22, 2021
 *      Author: mahmoud elkot
 */
#include "AlarmMonitor.h"

enum{
	alarm_monitor_waiting,
	alarm_monitor_alarm_on,
	alarm_monitor_alarm_off

}id_alarm_monitor;

void(*alarm_monitor_states)();

STATE_define(alarm_monitor_waiting){
	//printf("state = alarm_monitor_waiting");
	id_alarm_monitor = alarm_monitor_waiting;

    Delay(10);
    //change state!!! timer is expired
    //printf("timer is expired");
     alarm_monitor_states=STATE(alarm_monitor_alarm_off);

}
STATE_define(alarm_monitor_alarm_on){
	//printf("state = alarm_monitor_alarm_on");
	id_alarm_monitor = alarm_monitor_alarm_on;
     start_alarm();
	 alarm_monitor_states=STATE(alarm_monitor_waiting);
	 //printf("alarm_on");
}
STATE_define(alarm_monitor_alarm_off){
	//printf("state = alarm_monitor_alarm_off");
	id_alarm_monitor = alarm_monitor_alarm_off;
     stop_alarm();
     //printf("alarm_stop");
}
void high_pressure_detected(){
	//change state to alarm on
	alarm_monitor_states=STATE(alarm_monitor_alarm_on);

}
