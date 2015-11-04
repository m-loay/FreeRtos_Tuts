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
Tut3_2tasks_1periodicTask.lss \

FLASH_IMAGE += \
Tut3_2tasks_1periodicTask.hex \

EEPROM_IMAGE += \
Tut3_2tasks_1periodicTask.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Tut3_2tasks_1periodicTask.elf secondary-outputs

# Tool invocations
Tut3_2tasks_1periodicTask.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Tut3_2tasks_1periodicTask.map -mmcu=atmega32 -o "Tut3_2tasks_1periodicTask.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Tut3_2tasks_1periodicTask.lss: Tut3_2tasks_1periodicTask.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Tut3_2tasks_1periodicTask.elf  >"Tut3_2tasks_1periodicTask.lss"
	@echo 'Finished building: $@'
	@echo ' '

Tut3_2tasks_1periodicTask.hex: Tut3_2tasks_1periodicTask.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Tut3_2tasks_1periodicTask.elf  "Tut3_2tasks_1periodicTask.hex"
	@echo 'Finished building: $@'
	@echo ' '

Tut3_2tasks_1periodicTask.eep: Tut3_2tasks_1periodicTask.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Tut3_2tasks_1periodicTask.elf  "Tut3_2tasks_1periodicTask.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Tut3_2tasks_1periodicTask.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Tut3_2tasks_1periodicTask.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Tut3_2tasks_1periodicTask.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
