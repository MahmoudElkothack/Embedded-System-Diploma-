/*
 * pressure_sensir_driver.c
 *
 *  Created on: Oct 20, 2021
 *      Author: Mahmoud Elkot
 */
#include "pressure_sensor_driver.h"

int pressure=0;
void init(){
	//init stuff for driver
//printf("init state");
}

STATE_define(pressure_driver_read)  {
 id_pressure_driver_states= pressure_driver_read;

pressure=getPressureVal();
set_pressure_val(pressure);
//printf("pressure = %d",pressure);
//change state to wait for 10 sec
  Pressure_state = STATE(pressure_driver_waiting);

}
STATE_define(pressure_driver_waiting){
  id_pressure_driver_states = pressure_driver_waiting;
	//printf("waiting state");
	Delay(10);
	Pressure_state = STATE(pressure_driver_read);
	//change state to Read

}

