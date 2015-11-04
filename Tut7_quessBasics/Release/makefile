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
Tut7_quessBasics.lss \

FLASH_IMAGE += \
Tut7_quessBasics.hex \

EEPROM_IMAGE += \
Tut7_quessBasics.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Tut7_quessBasics.elf secondary-outputs

# Tool invocations
Tut7_quessBasics.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Tut7_quessBasics.map -mmcu=atmega32 -o "Tut7_quessBasics.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Tut7_quessBasics.lss: Tut7_quessBasics.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Tut7_quessBasics.elf  >"Tut7_quessBasics.lss"
	@echo 'Finished building: $@'
	@echo ' '

Tut7_quessBasics.hex: Tut7_quessBasics.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Tut7_quessBasics.elf  "Tut7_quessBasics.hex"
	@echo 'Finished building: $@'
	@echo ' '

Tut7_quessBasics.eep: Tut7_quessBasics.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Tut7_quessBasics.elf  "Tut7_quessBasics.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Tut7_quessBasics.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Tut7_quessBasics.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Tut7_quessBasics.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
