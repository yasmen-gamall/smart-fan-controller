################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD.c \
../HAL/dc_motor.c \
../HAL/lm35_sensor.c 

OBJS += \
./HAL/LCD.o \
./HAL/dc_motor.o \
./HAL/lm35_sensor.o 

C_DEPS += \
./HAL/LCD.d \
./HAL/dc_motor.d \
./HAL/lm35_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


