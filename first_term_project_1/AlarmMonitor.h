/*
 * AlarmMonitor.h
 *
 *  Created on: Oct 22, 2021
 *      Author: mahmoud elkot
 */

#ifndef ALARMMONITOR_H_
#define ALARMMONITOR_H_
#include "state.h"
#include <stdio.h>
#include "driver.h"
enum{
	alarm_monitor_waiting,
	alarm_monitor_alarm_on,
	alarm_monitor_alarm_off

}id_alarm_monitor;
STATE_define(alarm_monitor_waiting);
STATE_define(alarm_monitor_alarm_on);
STATE_define(alarm_monitor_alarm_off);
void(*alarm_monitor_states)();
#endif /* ALARMMONITOR_H_ */
