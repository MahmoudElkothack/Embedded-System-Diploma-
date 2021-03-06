/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
//Mahmoud Elkot    -->>>>DATE: 11/12/2021

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// register address  0x4001 0800  //input
#define GPIOA_BASE     0x40010800
#define GPIOA_CRH      *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_CRL      *(volatile uint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_ODR      *(volatile uint32_t *)(GPIOA_BASE + 0x0C)
#define GPIOA_IDR      *(volatile uint32_t *)(GPIOA_BASE +  0x08)
//#define GPIOA13         (1UL<<13)


#define RCC_BASE       0x40021000
#define RCC_APB2ENR    *(volatile uint32_t *)(RCC_BASE + 0x18)
#define RCC_IOPAEN     (1<<2)
#define RCC_IOPBEN     (1<<3)



// register address
#define GPIOB_BASE     0x40010C00
#define GPIOB_CRH      *(volatile uint32_t *)(GPIOB_BASE + 0x04)
#define GPIOB_CRL      *(volatile uint32_t *)(GPIOB_BASE + 0x00)
#define GPIOB_ODR      *(volatile uint32_t *)(GPIOB_BASE + 0x0C)
#define GPIOB_IDR      *(volatile uint32_t *)(GPIOB_BASE +  0x08h)
//#define GPIOA13         (1UL<<13)



void clock_init(){
	//enable clock GPIOA
	RCC_APB2ENR |= RCC_IOPAEN;
	//enable clock GPIOA
	RCC_APB2ENR |=RCC_IOPBEN;
}
void wait_time(int x){
	int i,j;
	for(i=0;i <=x ;i++)
		for(j=0;j<=1000;j++);


}
void GPIO_INIT(){


	//CLEAR IDR for PORTA
		GPIOA_IDR=0;
        GPIOA_CRH=0;
       GPIOA_CRL=0;

		//In input mode (MODE[1:0]=00):
	//00: Analog mode
	//01: Floating input (reset state)
	//10: Input with pull-up / pull-down
	//11: Reserved
	GPIOA_CRL &= ~(0b11<<4); //as  input  PA1
	GPIOA_CRL |= 0b01<<6; //as floating PA1


	GPIOA_CRH &= ~(0b11<<20); //as  input  PA1
	GPIOA_CRH |= 0b01 <<22;  // as floating

	//////////////////PORTB CONFIG //////

		GPIOB_CRL |= 0b0111<<4; //as output open drain PB1


		//GPIOB_CRH &= ~(0b11<<20); //as  input  PA1
		GPIOB_CRH |= 0b0111<<20;  // as output open drain PB13
}

int main (void)
{


	 clock_init();
	 GPIO_INIT();
while(1){
/////
	if(((GPIOA_IDR & (1<<1)) >>1) == 0){
         GPIOB_ODR  ^= 1<<1;
	 while(((GPIOA_IDR & (1<<1)) >>1) == 0);
	}

	 if(((GPIOA_IDR & (1<<13)) >>13) == 1)
	 {
	          GPIOB_ODR  ^= 1<<13;
	 	 //while((GPIOA_IDR &&0b10) >>1 == 0);
	 }
	 }
wait_time(10000);
}

