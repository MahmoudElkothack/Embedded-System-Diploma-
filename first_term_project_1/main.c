#include <stdint.h>
#include <stdio.h>
#include "pressure_sensor_driver.h"
#include "main_algo.h"
#include "AlarmMonitor.h"
#include "Alarmactuatordriver.h"
#include "driver.h"


void Setup_main(){
	Pressure_state = STATE(pressure_driver_read);
//Pressure_state = STATE(pressure_driver_read);
main_algo_states=STATE(high_pressure_decide);
alarm_monitor_states=STATE(alarm_monitor_alarm_off);
alarm_actuator_states=STATE(waiting);

}

int main (){
	GPIO_INITIALIZATION();
	Setup_main();
	while (1)
	{
		Pressure_state();
		main_algo_states();
		alarm_monitor_states();
		alarm_actuator_states();
		//Implement your Design
	}

}
