/*
 * DC.h
 *
 *  Created on: Oct 11, 2021
 *      Author: Mahmoud Elkot
 */

#ifndef DC_H_
#define DC_H_
#include "state.h"
#include <stdlib.h>
#include <stdio.h>
enum {
	DC_idel,
	DC_busy
}DC_state_id;

STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();
extern void (*DC_state)();




#endif /* DC_H_ */
