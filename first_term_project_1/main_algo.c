/*
 * main_algo.c
 *
 *  Created on: Oct 20, 2021
 *      Author: ALBORAQ
 */

#include "main_algo.h"
void(*main_algo_states)();
int threshold=20;
int pval=0;
enum{
	high_pressure_decide,

}id_main_algo_states;


STATE_define(high_pressure_decide){
 id_main_algo_states = high_pressure_decide;
	//(pval >= threshold)? :
if(pval <= threshold){
//printf("high pressure detected");
	high_pressure_detected();
}
//printf("pressure = %d\n",pval);

}
void set_pressure_val(int pressure){
	// if pressure is equal or bigger than threshold
	//(pressure >= threshold)? :
  pval=pressure;
  //change to high pressure decide
  main_algo_states = STATE(high_pressure_decide);

}
