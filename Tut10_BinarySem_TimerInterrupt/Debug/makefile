################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Tut10_BinarySem_TimerInterrupt.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Tut10_BinarySem_TimerInterrupt.elf secondary-outputs

# Tool invocations
Tut10_BinarySem_TimerInterrupt.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Tut10_BinarySem_TimerInterrupt.map -mmcu=atmega32 -o "Tut10_BinarySem_TimerInterrupt.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Tut10_BinarySem_TimerInterrupt.lss: Tut10_BinarySem_TimerInterrupt.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Tut10_BinarySem_TimerInterrupt.elf  >"Tut10_BinarySem_TimerInterrupt.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Tut10_BinarySem_TimerInterrupt.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Tut10_BinarySem_TimerInterrupt.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Tut10_BinarySem_TimerInterrupt.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
