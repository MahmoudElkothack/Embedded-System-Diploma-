/*
 * Stm32_F103C6_gpio_driver.c
 *
 *  Created on: Sep 18, 2021
 *      Author: hassan
 */
#include"Stm32_F103C6_gpio_driver.h"
//-----------------------------
/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/
/**================================================================
* @Fn-				MCAL_GPIO_Init
* @brief -			Initialize Specific pin in the port According to A Desired Mode
* @param [in] -		GPIOx Where x  Could Be(A,B,C,D,E)
* @param [out] -	None
* @retval -			None
* Note-				STM32F103C6 MCU has PORTS A,B,C,D,E
* 					While LQFP84 Has only A,B and Part of C,D
*/
void MCAL_GPIO_Init(GPIO_t *GPIOx, GPIO_PinConfig_t* pinconfig){
	//CRL used for pins from 0:7
	if((pinconfig->GPIO_Pin_Number)*4<32){
		GPIOx->CRL &=~(0xF<<((pinconfig->GPIO_Pin_Number)*4));
		GPIOx->CRL |=(pinconfig->GPIO_Mode<<((pinconfig->GPIO_Pin_Number)*4));
	}//CRH used to configure pins 8:15
	else{
		GPIOx->CRH &=~(0xF<<((pinconfig->GPIO_Pin_Number)*4-32));
		GPIOx->CRH |=(pinconfig->GPIO_Mode<<((pinconfig->GPIO_Pin_Number)*4-32));
	}
	/*Incase of Input Pull Down ODR should be set for the specific pin*/
	if (pinconfig->GPIO_Mode == GPIO_MODE_INPUT_PD)
		GPIOx->ODR |=(1<<pinconfig->GPIO_Pin_Number);

}
/**================================================================
* @Fn-				MCAL_GPIO_DeInit
* @brief -			Deinitialize a desired PORT
* @param [in] -		GPIOx Where x  Could Be(A,B,C,D,E)
* @param [out] -	None
* @retval -			None
* Note-				None
*/
void MCAL_GPIO_DeInit(GPIO_t *GPIOx){
	GPIOx->BRR =0x00000000;
	GPIOx->BSRR =0x00000000;
	GPIOx->CRH =0x44444444;
	GPIOx->CRL =0x44444444;
	//GPIOx->IDR =0x00000000; read only
	GPIOx->LCKR =0x00000000;
	GPIOx->ODR =0x00000000;
}
/**================================================================
* @Fn-				MCAL_GPIO_ReadPIN
* @brief -			Read the Value of A Specific pin
* @param [in] -		GPIOx Where x  Could Be(A,B,C,D,E)
* @retval -			value of the pin
* Note-				None
*/
uint8_t MCAL_GPIO_ReadPIN(GPIO_t *GPIOx, uint8_t Pin_Number){
	uint8_t value=(GPIOx->IDR>>Pin_Number);
	return value;
}
/**================================================================
* @Fn-				MCAL_GPIO_ReadPort
* @brief -			Read the Value of A Specific port
* @param [in] -		GPIOx Where x  Could Be(A,B,C,D,E)
* @retval -			value of the port
* Note-				None
*/
uint16_t MCAL_GPIO_ReadPort(GPIO_t *GPIOx){
	return (uint16_t)GPIOx->IDR;
}
/**================================================================
* @Fn-				MCAL_GPIO_ReadPort
* @brief -			Write A Value TO A Specific port
* @param [in] -		GPIOx Where x  Could Be(A,B,C,D,E)
* @param [out] -	None
* @retval -			None
* Note-				None
*/
void MCAL_GPIO_WritePort(GPIO_t *GPIOx, uint16_t value){
	GPIOx->ODR= value;
}
/**================================================================
* @Fn-				MCAL_GPIO_ReadPort
* @brief -			Write A Value TO A Specific pin
* @param [in] -		GPIOx Where x  Could Be(A,B,C,D,E)
* @param [out] -	None
* @retval -			None
* Note-				None
*/
void MCAL_GPIO_WritePin(GPIO_t *GPIOx, uint8_t Pin_Number,uint8_t value){
	if(!value)
		GPIOx->ODR &=~(1<<Pin_Number);
	else
		GPIOx->ODR |=(1<<Pin_Number);

}
/**================================================================
* @Fn-				MCAL_GPIO_ReadPort
* @brief -			Toggle A Specific pin
* @param [in] -		GPIOx Where x  Could Be(A,B,C,D,E)
* @param [out] -	None
* @retval -			None
* Note-				None
*/
void MCAL_GPIO_TogglePin(GPIO_t *GPIOx, uint8_t Pin_Number){
	GPIOx->ODR ^=(1<<Pin_Number);
}

uint8_t MCAL_GPIO_LockPin(GPIO_t *GPIOx, uint8_t Pin_Number){
//	LCKK[16]: Lock key
//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
//	0: Port configuration lock key not active
//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
//	LOCK key writing sequence:
//	Write 1
//	Write 0
//	Write 1
//	Read 0
//	Read 1 (this read is optional but confirms that the lock is active)
//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
//	Any error in the lock sequence will abort the lock
volatile uint32_t temp=(1<<16);
temp |=(1<<Pin_Number);
GPIOx->LCKR =temp;
GPIOx->LCKR =(1<<Pin_Number);
GPIOx->LCKR =temp;
temp =GPIOx->LCKR;
if((uint32_t)GPIOx->LCKR&(1<<16))
	return 1;
else return 0;
}


