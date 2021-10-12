/*
 * US.h
 *
 *  Created on: Oct 11, 2021
 *      Author: Mahmoud Elkot
 */

#ifndef US_H_
#define US_H_
#include "state.h"
#include <stdlib.h>
#include <stdio.h>
enum {
	US_busy,
}US_state_id;

STATE_define(US_busy);
//STATE_define(US_driving);

extern void (*US_state)();

void US_init();


#endif /* US_H_ */
