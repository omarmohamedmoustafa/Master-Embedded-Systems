################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6x\ COTS/DRIVERS/RCC/RCC.c 

OBJS += \
./STM32F103C6x\ COTS/DRIVERS/RCC/RCC.o 

C_DEPS += \
./STM32F103C6x\ COTS/DRIVERS/RCC/RCC.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6x\ COTS/DRIVERS/RCC/RCC.o: ../STM32F103C6x\ COTS/DRIVERS/RCC/RCC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Omar_/STM32CubeIDE/workspace_1.4.0/STM32F103C6_COTS/STM32F103C6x COTS/INCLUDES" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6x COTS/DRIVERS/RCC/RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

