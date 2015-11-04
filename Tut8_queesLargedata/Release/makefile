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
Tut8_queesLargedata.lss \

FLASH_IMAGE += \
Tut8_queesLargedata.hex \

EEPROM_IMAGE += \
Tut8_queesLargedata.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Tut8_queesLargedata.elf secondary-outputs

# Tool invocations
Tut8_queesLargedata.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Tut8_queesLargedata.map -mmcu=atmega32 -o "Tut8_queesLargedata.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Tut8_queesLargedata.lss: Tut8_queesLargedata.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Tut8_queesLargedata.elf  >"Tut8_queesLargedata.lss"
	@echo 'Finished building: $@'
	@echo ' '

Tut8_queesLargedata.hex: Tut8_queesLargedata.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -O ihex Tut8_queesLargedata.elf  "Tut8_queesLargedata.hex"
	@echo 'Finished building: $@'
	@echo ' '

Tut8_queesLargedata.eep: Tut8_queesLargedata.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Tut8_queesLargedata.elf  "Tut8_queesLargedata.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Tut8_queesLargedata.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Tut8_queesLargedata.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) Tut8_queesLargedata.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
