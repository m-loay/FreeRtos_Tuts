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
Tut12_CountingSem.lss \

FLASH_IMAGE += \
Tut12_CountingSem.hex \

EEPROM_IMAGE += \
Tut12_CountingSem.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Tut12_CountingSem.elf secondary-outputs

# Tool invocations
Tut12_CountingSem.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Tut12_CountingSem.map -mmcu=atmega32 -o "Tut12_CountingSem.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Tut12_CountingSem.lss: Tut12_CountingSem.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Tut12_CountingSem.elf  >"Tut12_CountingSem.lss"
	@echo 'Finished building: $@'
	@echo ' '

Tut12_CountingSem.hex: Tut12_CountingSem.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Tut12_CountingSem.elf  "Tut12_CountingSem.hex"
	@echo 'Finished building: $@'
	@echo ' '

Tut12_CountingSem.eep: Tut12_CountingSem.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Tut12_CountingSem.elf  "Tut12_CountingSem.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Tut12_CountingSem.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Tut12_CountingSem.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Tut12_CountingSem.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
