################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../croutine.c \
../heap_1.c \
../list.c \
../main.c \
../port.c \
../queue.c \
../tasks.c \
../timer_int.c \
../timers.c \
../usart.c 

OBJS += \
./croutine.o \
./heap_1.o \
./list.o \
./main.o \
./port.o \
./queue.o \
./tasks.o \
./timer_int.o \
./timers.o \
./usart.o 

C_DEPS += \
./croutine.d \
./heap_1.d \
./list.d \
./main.d \
./port.d \
./queue.d \
./tasks.d \
./timer_int.d \
./timers.d \
./usart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


