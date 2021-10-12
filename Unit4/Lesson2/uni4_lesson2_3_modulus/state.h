/*
 * state.h
 *
 *  Created on: Oct 11, 2021
 *      Author: ALBORAQ
 */

#ifndef STATE_H_
#define STATE_H_
#define STATE_define(_statfun_) void st_##_statfun_()
#define STATE(_statfun_)  st_##_statfun_

//state interfaces

void US_set_distance(int d);
void motor_set(int speed);


#endif /* STATE_H_ */
