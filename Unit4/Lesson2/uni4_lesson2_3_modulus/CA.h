/*
 * CA.h
 *
 *  Created on: Oct 11, 2021
 *      Author: Mahmoud Elkot
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
#include <stdlib.h>
#include <stdio.h>
enum {
	CA_waiting,
	CA_driving
}CA_state_id;

STATE_define(CA_waiting);
STATE_define(CA_driving);

extern void (*ca_state)();




#endif /* CA_H_ */
