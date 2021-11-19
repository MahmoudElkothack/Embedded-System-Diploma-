/*
 * Stm32_F103C6_gpio_driver.h
 *
 *  Created on: Sep 18, 2021
 *      Author: hassan
 */

#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_

//Includes
#include<stm32f103x6.h>


//-----------------------------
//CONFIG (structures)
typedef struct{
	uint8_t GPIO_Mode;			/*Specifies The Operation Mode for The Pin
	 	 	 	 	 	 	  	  And Can be valued of @ref GPIO_MODE_Define*/
	uint8_t GPIO_Pin_Number;	/*Specifies The The Pin Number
	 	 	 	 	 	 	  	  And Can be valued of @ref GPIO_Pin_Define*/

}GPIO_PinConfig_t;
//Macros Configuration References
#define GPIO_PIN_SET 		1
#define GPIO_PIN_RESET 		0
//-----------------------------
/*@ref Module_REF_NAME_define
*/
/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/
void MCAL_GPIO_Init(GPIO_t *GPIOx, GPIO_PinConfig_t* pinconfig);
void MCAL_GPIO_DeInit(GPIO_t *GPIOx);
uint8_t MCAL_GPIO_ReadPIN(GPIO_t *GPIOx, uint8_t Pin_Number);
uint16_t MCAL_GPIO_ReadPort(GPIO_t *GPIOx);
void MCAL_GPIO_WritePort(GPIO_t *GPIOx, uint16_t value);
void MCAL_GPIO_WritePin(GPIO_t *GPIOx, uint8_t Pin_Number,uint8_t value);
void MCAL_GPIO_TogglePin(GPIO_t *GPIOx, uint8_t Pin_Number);
uint8_t MCAL_GPIO_LockPin(GPIO_t *GPIOx, uint8_t Pin_Number);
//====================================================
//@ref GPIO_MODE_Define
/*In input mode (MODE[1:0]=00):
00: Analog mode
01: Floating input (reset state)
10: Input with pull-up / pull-down
11: Reserved
In output mode (MODE[1:0] > 00):
00: General purpose output push-pull
01: General purpose output Open-drain
10: Alternate function output Push-pull
11: Alternate function output Open-drain
MODEy[1:0]: Port x mode bits (y= 0 .. 7)
These bits are written by software to configure the corresponding I/O port.
00: Input mode (reset state)
01: Output mode, max speed 10 MHz.
10: Output mode, max speed 2 MHz.
11: Output mode, max speed 50 MH*/
#define GPIO_MODE_ANALOG			0x00u	//ANALOG Mode
#define GPIO_MODE_INPUT_F			0x04u	//INPUT Floating
#define GPIO_MODE_INPUT_PP			0x08u	//Input Pull_UP
#define GPIO_MODE_INPUT_PD			0x08u	//INPUT_Pull_Down
#define GPIO_MODE_OUTPUT_PP_10M		0x01u	//OUTput_push_pull_10M
#define GPIO_MODE_OUTPUT_OD_10M		0x05u	//OUTput_OPEN_DRAIN_10M
#define GPIO_MODE_AF_PP_10M			0x09u	//ALTERNATIVE_FUNCTION_OUTPUT_PUSH_PULL_10M
#define GPIO_MODE_AF_OD_10M			0x0Du	//ALTERNATIVE_FUNCTION_OUTPUT_OPEN_DRAIN_10M
#define GPIO_MODE_OUTPUT_PP_2M		0x02u	//OUTput_push_pull_2M
#define GPIO_MODE_OUTPUT_OD_2M		0x06u	//OUTput_OPEN_DRAIN_2M
#define GPIO_MODE_AF_PP_2M			0x0Au	//ALTERNATIVE_FUNCTION_OUTPUT_PUSH_PULL_2M
#define GPIO_MODE_AF_OD_2M			0x0Eu	//ALTERNATIVE_FUNCTION_OUTPUT_OPEN_DRAIN_2M
#define GPIO_MODE_OUTPUT_PP_50M		0x03u	//OUTput_push_pull_50M
#define GPIO_MODE_OUTPUT_OD_50M		0x07u	//OUTput_OPEN_DRAIN_50M
#define GPIO_MODE_AF_PP_50M			0x0Bu	//ALTERNATIVE_FUNCTION_OUTPUT_PUSH_PULL_50M
#define GPIO_MODE_AF_OD_50M			0x0Fu	//ALTERNATIVE_FUNCTION_OUTPUT_OPEN_DRAIN_50M
//================================================================================
//================================================================================
/*@ref GPIO_Pin_Define*/
#define GPIO_Pin_0			0x00u
#define GPIO_Pin_1			0x01u
#define GPIO_Pin_2			0x02u
#define GPIO_Pin_3			0x03u
#define GPIO_Pin_4			0x04u
#define GPIO_Pin_5			0x05u
#define GPIO_Pin_6			0x06u
#define GPIO_Pin_7			0x07u
#define GPIO_Pin_8			0x08u
#define GPIO_Pin_9			0x09u
#define GPIO_Pin_10			0x0Au
#define GPIO_Pin_11			0x0Bu
#define GPIO_Pin_12			0x0Cu
#define GPIO_Pin_13			0x0Du
#define GPIO_Pin_14			0x0Eu
#define GPIO_Pin_15			0x0Fu
//================================================================================
#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
