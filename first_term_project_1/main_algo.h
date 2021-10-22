/*
 * main_algo.h
 *
 *  Created on: Oct 20, 2021
 *      Author: mahmoud elkot
 */

#ifndef MAIN_ALGO_H_
#define MAIN_ALGO_H_
#include "state.h"
#include <stdio.h>
enum{
	high_pressure_decide,

}id_main_algo_states;
STATE_define(high_pressure_decide);
void(*main_algo_states)();
#endif /* MAIN_ALGO_H_ */

