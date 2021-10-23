/*
 * Alarmactuatordriver.h
 *
 *  Created on: Oct 22, 2021
 *      Author: mahmoud elkot

 */

#ifndef ALARMACTUATORDRIVER_H_
#define ALARMACTUATORDRIVER_H_
#include "state.h"
#include "driver.h"
#include <stdio.h>



void init();
STATE_define(alarm_on);
STATE_define(alarm_off);
STATE_define(waiting);
extern void (*alarm_actuator_states)();
#endif /* ALARMACTUATORDRIVER_H_ */
