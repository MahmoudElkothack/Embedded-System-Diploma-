################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GPIO/GPIO.c 

OBJS += \
./MCAL/GPIO/GPIO.o 

C_DEPS += \
./MCAL/GPIO/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GPIO/GPIO.o: ../MCAL/GPIO/GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"E:/Embedded System Diploma/Diploma Repo/Embedded-System-Diploma-/Unit8/lesson3_UART2/STM32F103xx_Drivers/MCAL/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/GPIO/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

