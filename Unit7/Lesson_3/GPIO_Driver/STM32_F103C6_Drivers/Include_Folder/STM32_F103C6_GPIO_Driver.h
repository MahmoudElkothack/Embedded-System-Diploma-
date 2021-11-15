/*
 * STM32_F103C6_GPIO_Driver.h
 *
 *  Created on: 15/11/2021
 *      Author: Mahmoud Elkot
 */

#ifndef INCLUDE_FOLDER_STM32_F103C6_GPIO_DRIVER_H_
#define INCLUDE_FOLDER_STM32_F103C6_GPIO_DRIVER_H_

/* =========================== Includes =========================== */
#include "STM32F103X6.h"

/* ================= Structure Configuration ====================== */
typedef struct
{
	// CRL : low   0 : 7
	// CRH : high  8 : 15

	uint16_t GPIO_Pin_Number;  // Specifies the GPIO pins to be configured.
							   // This parameter can be a value of @ref GPIO_PINS_DEFINE

	uint8_t GPIO_MODE;         // Specifies the operation mode for the selected pins
							   // This parameter can be a value of @ref GPIO_MODE_DEFINE

	uint8_t GPIO_Output_Speed; // Specifies the speed for the selected pins
							   // This parameter can be a value of @ref GPIO_SPEED_define

}GPIO_PinConfig_t;  // t : means type definition

/* ====================== Macros Configuration Reference ======================= */

// @ref GPIO_PINS_define
#define GPIO_PIN_0					((uint16_t)0x0001)  // pin 0 selected
#define GPIO_PIN_1					((uint16_t)0x0002)  // pin 1 selected
#define GPIO_PIN_2					((uint16_t)0x0004)  // pin 2 selected
#define GPIO_PIN_3					((uint16_t)0x0008)  // pin 3 selected
#define GPIO_PIN_4					((uint16_t)0x0010)  // pin 4 selected
#define GPIO_PIN_5					((uint16_t)0x0020)  // pin 5 selected
#define GPIO_PIN_6					((uint16_t)0x0040)  // pin 6 selected
#define GPIO_PIN_7					((uint16_t)0x0080)  // pin 7 selected
#define GPIO_PIN_8					((uint16_t)0x0100)  // pin 8 selected
#define GPIO_PIN_9					((uint16_t)0x0200)  // pin 9 selected
#define GPIO_PIN_10					((uint16_t)0x0400)  // pin 10 selected
#define GPIO_PIN_11					((uint16_t)0x0800)  // pin 11 selected
#define GPIO_PIN_12					((uint16_t)0x1000)  // pin 12 selected
#define GPIO_PIN_13					((uint16_t)0x2000)  // pin 13 selected
#define GPIO_PIN_14					((uint16_t)0x4000)  // pin 14 selected
#define GPIO_PIN_15					((uint16_t)0x8000)  // pin 15 selected
#define GPIO_PIN_ALL				((uint16_t)0xFFFF)  // All pins are selected

#define GPIO_PIN_MASK				0x0000FFFFu  // pin mask for assert test


// @ref GPIO_MODE_define
// 0 : Analog mode
#define GPIO_MODE_ANALOG			0x00000000u
// 1 : Floating input ( reset state )
#define GPIO_MODE_INPUT_FLOATING	0x00000001u
// 2 : Input with pull-up
#define GPIO_MODE_INPUT_PUR			0x00000002u
// 3 : pull-down
#define GPIO_MODE_INPUT_PDR			0x00000003u
// 4 : General purpose output push-pull
#define GPIO_MODE_OUTPUT_PP			0x00000004u
// 5 : General purpose output open-drain
#define GPIO_MODE_OUTPUT_OD			0x00000005u
// 6 : Alternative function output push-pull
#define GPIO_MODE_OUTPUT_AF_PP		0x00000006u
// 7 : Alternative function output open-drain
#define GPIO_MODE_OUTPUT_AF_OD		0x00000007u
// 8 : Alternative function input ( floating )
#define GPIO_MODE_AF_INPUT			0x00000008u


// @ref GPIO_SPEED_define
// 1 : Output mode, max speed 10 MHz
#define GPIO_SPEED_10M				0x00000001u
// 2 : Output mode, max speed 2 MHz
#define GPIO_SPEED_2M				0x00000002u
// 3 : Output mode, max speed 50 MHz
#define GPIO_SPEED_50M				0x00000003u


// @ref GPIO_PIN_state
#define GPIO_PIN_SET		1
#define GPIO_PIN_RESET		0


// @ref GPIO_RETURN_LOCK
#define GPIO_RETURN_LOCK_Enabled		1
#define GPIO_RETURN_LOCK_ERROR			0

/* ===================== APIs Supported by "MCAL GPIO DRIVER" =========================== */

void MCAL_GPIO_Init (GPIO_TypeDef *GPIO_PortX, GPIO_PinConfig_t* PinConfig);  // Pointer of type GPIO_TypeDef points at the base
													 // address of GPIO_PORTX . X can be : A,B,C,D,E
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIO_PortX);


uint8_t MCAL_GPIO_ReadPin   (GPIO_TypeDef *GPIO_PortX, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort (GPIO_TypeDef *GPIO_PortX);

void MCAL_GPIO_WritePin     (GPIO_TypeDef *GPIO_PortX, uint16_t PinNumber, uint8_t Value);
void MCAL_GPIO_WritePort    (GPIO_TypeDef *GPIO_PortX, uint16_t Value);

void MCAL_GPIO_TogglePin    (GPIO_TypeDef *GPIO_PortX, uint16_t PinNumber);

uint8_t MCAL_GPIO_LockPin   (GPIO_TypeDef *GPIO_PortX, uint16_t PinNumber);

#endif /* INCLUDE_FOLDER_STM32_F103C6_GPIO_DRIVER_H_ */
