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



enum{

	pressure_driver_read,
	pressure_driver_waiting

}id_pressure_driver_states;
void init();
	//init stuff for driver
//void Read_pressure();
STATE_define(pressure_driver_read);
STATE_define(pressure_driver_waiting);
void (*Pressure_state)();
#endif /* PRESSURE_SENSOR_DRIVER_H_ */
