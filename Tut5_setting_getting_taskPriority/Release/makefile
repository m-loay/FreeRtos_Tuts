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
Tut5_setting_getting_taskPriority.lss \

FLASH_IMAGE += \
Tut5_setting_getting_taskPriority.hex \

EEPROM_IMAGE += \
Tut5_setting_getting_taskPriority.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Tut5_setting_getting_taskPriority.elf secondary-outputs

# Tool invocations
Tut5_setting_getting_taskPriority.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Tut5_setting_getting_taskPriority.map -mmcu=atmega32 -o "Tut5_setting_getting_taskPriority.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Tut5_setting_getting_taskPriority.lss: Tut5_setting_getting_taskPriority.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Tut5_setting_getting_taskPriority.elf  >"Tut5_setting_getting_taskPriority.lss"
	@echo 'Finished building: $@'
	@echo ' '

Tut5_setting_getting_taskPriority.hex: Tut5_setting_getting_taskPriority.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Tut5_setting_getting_taskPriority.elf  "Tut5_setting_getting_taskPriority.hex"
	@echo 'Finished building: $@'
	@echo ' '

Tut5_setting_getting_taskPriority.eep: Tut5_setting_getting_taskPriority.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Tut5_setting_getting_taskPriority.elf  "Tut5_setting_getting_taskPriority.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Tut5_setting_getting_taskPriority.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Tut5_setting_getting_taskPriority.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Tut5_setting_getting_taskPriority.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
