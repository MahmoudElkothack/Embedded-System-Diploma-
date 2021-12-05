################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/main.o: ../Src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F030C6Tx -c -I../Inc -I"E:/Embedded System Diploma/subfolder fromgithub/Lesson7/Drivers_1_1/HAL" -I"E:/Embedded System Diploma/subfolder fromgithub/Lesson7/Drivers_1_1/STM32F103C6_Drivers/MCAL" -I"E:/Embedded System Diploma/subfolder fromgithub/Lesson7/Drivers_1_1/STM32F103C6_Drivers/LIB" -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"Src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/syscalls.o: ../Src/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F030C6Tx -c -I"E:/Embedded System Diploma/subfolder fromgithub/Lesson7/Drivers_1_1/HAL" -I"E:/Embedded System Diploma/subfolder fromgithub/Lesson7/Drivers_1_1/STM32F103C6_Drivers" -I"E:/Embedded System Diploma/subfolder fromgithub/Lesson7/Drivers_1_1/STM32F103C6_Drivers/LIB" -I"E:/Embedded System Diploma/subfolder fromgithub/Lesson7/Drivers_1_1/STM32F103C6_Drivers/MCAL" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"Src/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Src/sysmem.o: ../Src/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DSTM32 -DSTM32F0 -DDEBUG -DSTM32F030C6Tx -c -I"E:/Embedded System Diploma/subfolder fromgithub/Lesson7/Drivers_1_1/HAL" -I"E:/Embedded System Diploma/subfolder fromgithub/Lesson7/Drivers_1_1/STM32F103C6_Drivers" -I"E:/Embedded System Diploma/subfolder fromgithub/Lesson7/Drivers_1_1/STM32F103C6_Drivers/LIB" -I"E:/Embedded System Diploma/subfolder fromgithub/Lesson7/Drivers_1_1/STM32F103C6_Drivers/MCAL" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -gdwarf-2 -fstack-usage -MMD -MP -MF"Src/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

