/*
 * Stm32_F103C6_EXTI_driver.c
 *
 *  Created on: 19/11/2021
 *      Author: Mahmoud Elkot
 */
#include"Stm32_F103C6_EXTI_driver.h"
//-----------------------------
/*
 * ===============================================
 * Generic Variables by "MCAL EXTI DRIVER"
 * ===============================================
 */
void (*GP_CallBack[15])(void);
/*
 * ===============================================
 * Generic Macros by "MCAL EXTI DRIVER"
 * ===============================================
 */
#define AFIO_GPIO_EXTI_Mapping(x)  ((x==GPIOA)?0:\
									(x==GPIOB)?1:\
									(x==GPIOC)?2:\
									(x==GPIOD)?3:0)
/*
 * ===============================================
 * Generic Functions by "MCAL EXTI DRIVER"
 * ===============================================
 */
void Enable_NVIC(uint16_t N){
	switch(N){
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable;
		break;

	}
}
void Disable_NVIC(uint16_t N){
	switch(N){
	case 0:
		NVIC_IRQ6_EXTI0_Disable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Disable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Disable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Disable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Disable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Disable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Disable;
		break;
	}
}
void Update_EXTI(EXTI_PinConfig_t *EXTI_Config){
	//AFIO Pin Floating
	GPIO_PinConfig_t PINCONFIG;
	PINCONFIG.GPIO_Pin_Number=EXTI_Config->EXTI_PIN.GPIO_PIN;
	PINCONFIG.GPIO_Mode = GPIO_MODE_INPUT_F;
	MCAL_GPIO_Init(EXTI_Config->EXTI_PIN.GPIO_Port, &PINCONFIG);
	//Routing AFIO EXTI TO THE DESIRED PORT
	uint8_t AFIO_EXTICR_Index=EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number/4;
	uint8_t AFIO_EXTICR_Shift_Position=(EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number%4)*4;

	AFIO->EXTICR[AFIO_EXTICR_Index] &=~(0xF<<AFIO_EXTICR_Shift_Position);
	AFIO->EXTICR[AFIO_EXTICR_Index]|=(AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port)<<AFIO_EXTICR_Shift_Position);
	//Unmasking the desired EXTI
	EXTI->IMR |=(1<<EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
	//Configuring Triggering Edge And Updating It
	EXTI->FTSR &=~(1<<EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
	EXTI->RTSR &=~(1<<EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
	switch(EXTI_Config->Trigger_Case){
	case EXTI_Trigger_RISING:
		EXTI->RTSR |=(1<<EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
		break;
	case EXTI_Trigger_FALLING:
		EXTI->FTSR |=(1<<EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
		break;
	case EXTI_Trigger_RISING_FALLING:
		EXTI->FTSR |=(1<<EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
		EXTI->RTSR |=(1<<EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number);
		break;
	}
	//Update IRQ Handling Callbackk
	GP_CallBack[EXTI_Config->EXTI_PIN.EXTI_Input_Line_Number]=EXTI_Config->P_IRQ_CALLBACK;
	//Enable Or Disable IRQ and NVIC
	switch(EXTI_Config->IRQ_EN){
	case EXTI_IRQ_Enable:
		EXTI->IMR |=(1<<EXTI_Config->EXTI_PIN.GPIO_PIN);
		Enable_NVIC(EXTI_Config->EXTI_PIN.GPIO_PIN);
		break;
	case EXTI_IRQ_Disable:
		EXTI->IMR &=~(1<<EXTI_Config->EXTI_PIN.GPIO_PIN);
		Disable_NVIC(EXTI_Config->EXTI_PIN.GPIO_PIN);
		break;

	}

}
/*
 * ===============================================
 * APIs Supported by "MCAL EXTI DRIVER"
 * ===============================================
 */
/**================================================================
 * @Fn-				MCAL_EXTI_Init
 * @brief -			Initialize Specific pin in the port to be used As EXTI
 * @param [in] -	Cofiguration structure
 * @param [out] -	None
 * @retval -			None
 * Note-				STM32F103C6 MCU has PORTS A,B,C,D,E
 * 					While LQFP84 Has only A,B and Part of C,D
 */
void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t *EXTI_Config){
	Update_EXTI(EXTI_Config);
}
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t *EXTI_Config){
	Update_EXTI(EXTI_Config);
}
/**================================================================
 * @Fn-				MCAL_EXTI_DeInit
 * @brief -			Reset EXTI Registers and NVIC
 * @param [in] -		void
 * @param [out] -	void
 * @retval -			void
 * Note-				STM32F103C6 MCU has PORTS A,B,C,D,E
 * 					While LQFP84 Has only A,B and Part of C,D
 */
void MCAL_EXTI_GPIO_DeInit(void){
	EXTI->IMR = 0x00000000;
	EXTI->EMR = 0x00000000;
	EXTI->RTSR = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->SWIER = 0x00000000;
	//EXTI->PR Clear By Write One
	EXTI->PR = 0xFFFFFFFF;
	//NVIC Reset For EXTI
	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;
}


void EXTI0_IRQHandler(void){
	//Clear Pending Register
	EXTI->PR |=(1<<0);
	//CALL IRQ CALL
	GP_CallBack[0]();

}
void EXTI1_IRQHandler(void){
	EXTI->PR |=(1<<1);
	//CALL IRQ CALL
	GP_CallBack[1]();
}
void EXTI2_IRQHandler(void){
	EXTI->PR |=(1<<2);
	//CALL IRQ CALL
	GP_CallBack[2]();
}
void EXTI3_IRQHandler(void){
	EXTI->PR |=(1<<3);
	//CALL IRQ CALL
	GP_CallBack[3]();
}
void EXTI4_IRQHandler(void){
	EXTI->PR |=(1<<4);
	//CALL IRQ CALL
	GP_CallBack[4]();
}
void EXTI9_5_IRQHandler(void){
	if(EXTI->PR &(1<<5)){
		EXTI->PR |=(1<<5);
		//CALL IRQ CALL
		GP_CallBack[5]();
	}
	if(EXTI->PR &(1<<6)){
		EXTI->PR |=(1<<6);
		//CALL IRQ CALL
		GP_CallBack[6]();
	}
	if(EXTI->PR &(1<<7)){
		EXTI->PR |=(1<<7);
		//CALL IRQ CALL
		GP_CallBack[7]();
	}
	if(EXTI->PR &(1<<8)){
		EXTI->PR |=(1<<8);
		//CALL IRQ CALL
		GP_CallBack[8]();
	}
	if(EXTI->PR &(1<<9)){
		EXTI->PR |=(1<<9);
		//CALL IRQ CALL
		GP_CallBack[9]();
	}

}
void EXTI15_10_IRQHandler(void){
	if(EXTI->PR &(1<<10)){
		EXTI->PR |=(1<<10);
		//CALL IRQ CALL
		GP_CallBack[10]();
	}
	if(EXTI->PR &(1<<11)){
		EXTI->PR |=(1<<11);
		//CALL IRQ CALL
		GP_CallBack[11]();
	}
	if(EXTI->PR &(1<<12)){
		EXTI->PR |=(1<<12);
		//CALL IRQ CALL
		GP_CallBack[12]();
	}
	if(EXTI->PR &(1<<13)){
		EXTI->PR |=(1<<13);
		//CALL IRQ CALL
		GP_CallBack[13]();
	}
	if(EXTI->PR &(1<<14)){
		EXTI->PR |=(1<<14);
		//CALL IRQ CALL
		GP_CallBack[14]();
	}
	if(EXTI->PR &(1<<15)){
		EXTI->PR |=(1<<15);
		//CALL IRQ CALL
		GP_CallBack[15]();
	}
}
