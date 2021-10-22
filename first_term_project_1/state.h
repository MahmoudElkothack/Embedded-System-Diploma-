/*
 * state.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Mahmoud elkot
 */

#ifndef STATE_H_
#define STATE_H_

#define STATE_define(_statfun_) void st_##_statfun_()
#define STATE(_statfun_)  st_##_statfun_

//state interfaces
void set_pressure_val(int pre);
void high_pressure_detected();
void start_alarm();
void stop_alarm();
#endif /* STATE_H_ */
