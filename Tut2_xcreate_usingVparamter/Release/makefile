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
Tut2_xcreate_usingVparamter.lss \

FLASH_IMAGE += \
Tut2_xcreate_usingVparamter.hex \

EEPROM_IMAGE += \
Tut2_xcreate_usingVparamter.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Tut2_xcreate_usingVparamter.elf secondary-outputs

# Tool invocations
Tut2_xcreate_usingVparamter.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Tut2_xcreate_usingVparamter.map -mmcu=atmega32 -o "Tut2_xcreate_usingVparamter.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Tut2_xcreate_usingVparamter.lss: Tut2_xcreate_usingVparamter.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Tut2_xcreate_usingVparamter.elf  >"Tut2_xcreate_usingVparamter.lss"
	@echo 'Finished building: $@'
	@echo ' '

Tut2_xcreate_usingVparamter.hex: Tut2_xcreate_usingVparamter.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Tut2_xcreate_usingVparamter.elf  "Tut2_xcreate_usingVparamter.hex"
	@echo 'Finished building: $@'
	@echo ' '

Tut2_xcreate_usingVparamter.eep: Tut2_xcreate_usingVparamter.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Tut2_xcreate_usingVparamter.elf  "Tut2_xcreate_usingVparamter.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Tut2_xcreate_usingVparamter.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Tut2_xcreate_usingVparamter.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Tut2_xcreate_usingVparamter.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
