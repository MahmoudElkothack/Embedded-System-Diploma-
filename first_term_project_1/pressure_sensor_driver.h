/*
 * pressure_sensor_driver.h
 *
 *  Created on: Oct 20, 2021
 *      Author: mahmoud elkot
 */

#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_
//#include "driver/driver.h"
//#include "main_algo.h"
#include "state.h"
#include <stdio.h>
#include "driver.h"




void init();
	//init stuff for driver
//void Read_pressure();
STATE_define(pressure_driver_read);
STATE_define(pressure_driver_waiting);
extern void (*Pressure_state)();
#endif /* PRESSURE_SENSOR_DRIVER_H_ */
