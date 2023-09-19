################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include STM32F103C6x\ COTS/DRIVERS/GPIO/subdir.mk
-include STM32F103C6x\ COTS/DRIVERS/EXTI/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32F103C6_COTS.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32F103C6_COTS.list \

OBJCOPY_BIN += \
STM32F103C6_COTS.bin \


# All Target
all:
	+@make --no-print-directory main-build && make --no-print-directory post-build

# Main-build Target
main-build: STM32F103C6_COTS.elf secondary-outputs

# Tool invocations
STM32F103C6_COTS.elf: $(OBJS) $(USER_OBJS) C:\Users\Omar_\STM32CubeIDE\workspace_1.4.0\STM32F103C6_COTS\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "STM32F103C6_COTS.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\Omar_\STM32CubeIDE\workspace_1.4.0\STM32F103C6_COTS\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32F103C6_COTS.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32F103C6_COTS.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32F103C6_COTS.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32F103C6_COTS.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32F103C6_COTS.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	arm-none-eabi-objcopy -O ihex STM32F103C6_COTS.elf STM32F103C6_COTS.hex
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
