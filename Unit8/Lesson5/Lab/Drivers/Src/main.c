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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include "stm32_f103c6_SPI_drivers.h"
#include "stm32_f103c6_USART_drivers.h"


#define SPI_MCU_MASTER_MODE
//#define SPI_MCU_SLAVE_MODE

uint8_t Buffer;

void SPI1_Interrupt_Handler(struct S_IRQ_Src irq)
{

#ifdef SPI_MCU_SLAVE_MODE
	if(irq.RXNE)
	{
		MCAL_SPI_Recieve_Data(SPI1, &Buffer, Polling_disable);
		MCAL_UART_SendData(USART1, &Buffer, enable);
	}

#endif
}


void Usart_Interrupt_Handler(void)
{

#ifdef SPI_MCU_MASTER_MODE
	MCAL_UART_ReceiveData(USART1, &Buffer, disable);
	MCAL_UART_SendData(USART1, &Buffer, enable);

	////Send Data With SPI
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, WRITE_PIN_LOW);		//NSS LOW
	MCAL_SPI_TX_RX(SPI1, &Buffer, Polling_enable);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, WRITE_PIN_HIGH);		//NSS HIGH
#endif

}

void clock_init(void)
{
	//Enable clock for GPIOA
	RCC_GPIOA_CLK_EN();
	//Enable clock for GPIOB
	RCC_GPIOB_CLK_EN();
	//Enable clock for AFIO
	RCC_AFIO_CLK_EN();
}


int main(void)
{
	clock_init();
	//==========================UART==========================
	USART_CONFIG_t UART_cfg;
	UART_cfg.USART_Mode = USART_MODE_TX_RX;
	UART_cfg.BaudRate_Speed = UART_BAUDRATE_SPEED_115200;
	UART_cfg.FLOW_CTRL = UART_FLOWCTRL_NONE;
	UART_cfg.Parity = UART_PARITY_DISABLE;
	UART_cfg.PayLoad_Data = UART_PAYLOAD_DATA_8BIT;
	UART_cfg.IRQ_ENABLE = UART_IRQ_ENABLE_RXNE;
	UART_cfg.Stop_bits = UART_STOP_BITS_1BIT;
	UART_cfg.P_IRQ_CallBack = Usart_Interrupt_Handler;
	MCAL_UART_Init(USART1, &UART_cfg);
	MCAL_UART_GPIO_Set_Pins(USART1);
	//==========================SPI==========================
	SPI_Pinconfig_t SPI_Cfg;
#ifdef SPI_MCU_MASTER_MODE
	SPI_Cfg.SPI_MODE = SPI_MODE_MASTER;
	SPI_Cfg.BAUDERATE_PRESCALER = BAUDERATE_PRESCALER_FCLK_DIVIDE_BY_8;
	SPI_Cfg.NSS_MANGEMENT = NSS_MANGEMENT_SOFTWARE_SSI_SET;
	SPI_Cfg.IRQ_ENABLE = IRQ_ENABLE_NONE;
	SPI_Cfg.P_IRQ_CallBack = NULL;
	//Configure GPIOA Pin 4 with NSS of SPI1
	GPIO_Pinconfig_t SPI_GPIO_Config;
	SPI_GPIO_Config.PinNumber = GPIO_PIN_4;
	SPI_GPIO_Config.Mode = GPIO_MODE_Output_PP;
	SPI_GPIO_Config.Output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOA, &SPI_GPIO_Config);
	MCAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, WRITE_PIN_HIGH);		//NSS HIGH
#endif

#ifdef SPI_MCU_SLAVE_MODE
	SPI_Cfg.SPI_MODE = SPI_MODE_SLAVE;
	SPI_Cfg.NSS_MANGEMENT = NSS_MANGEMENT_SLAVE_HARDWARE;
	SPI_Cfg.IRQ_ENABLE = IRQ_ENABLE_RXNEIE;
	SPI_Cfg.P_IRQ_CallBack = SPI1_Interrupt_Handler;
#endif

	SPI_Cfg.FRAME_FORMAT = FRAME_FORMAT_MSB_FIRST;
	SPI_Cfg.FRAME_SIZE = FRAME_SIZE_8BIT;
	SPI_Cfg.COMMUNICATION_MODE = COMMUNICATION_MODE_2LINE_FULL_DUPLEX;
	SPI_Cfg.CLK_POLARITY = CLK_POLARITY_IDLE_HIGH;
	SPI_Cfg.CLK_PHASE = CLK_POLARITY_SECOND_CLK_CAPTURE;
	MCAL_SPI_Init(SPI1, &SPI_Cfg);
	MCAL_SPI_GPIO_Set_Pins(SPI1);

    while(1)
    {

    }
}
