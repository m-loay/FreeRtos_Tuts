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
Tut4_CooperativeTasks.lss \

FLASH_IMAGE += \
Tut4_CooperativeTasks.hex \

EEPROM_IMAGE += \
Tut4_CooperativeTasks.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Tut4_CooperativeTasks.elf secondary-outputs

# Tool invocations
Tut4_CooperativeTasks.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Tut4_CooperativeTasks.map -mmcu=atmega32 -o "Tut4_CooperativeTasks.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Tut4_CooperativeTasks.lss: Tut4_CooperativeTasks.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Tut4_CooperativeTasks.elf  >"Tut4_CooperativeTasks.lss"
	@echo 'Finished building: $@'
	@echo ' '

Tut4_CooperativeTasks.hex: Tut4_CooperativeTasks.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Tut4_CooperativeTasks.elf  "Tut4_CooperativeTasks.hex"
	@echo 'Finished building: $@'
	@echo ' '

Tut4_CooperativeTasks.eep: Tut4_CooperativeTasks.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Tut4_CooperativeTasks.elf  "Tut4_CooperativeTasks.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Tut4_CooperativeTasks.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Tut4_CooperativeTasks.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Tut4_CooperativeTasks.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
