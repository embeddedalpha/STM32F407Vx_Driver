################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CAN/CAN.c 

OBJS += \
./CAN/CAN.o 

C_DEPS += \
./CAN/CAN.d 


# Each subdirectory must supply rules for building sources it contributes
CAN/%.o CAN/%.su CAN/%.cyclo: ../CAN/%.c CAN/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VETx -c -I../Inc -I"D:/STM32F407_Firmware/Driver/CAN" -I"D:/STM32F407_Firmware/Driver/GPIO" -I"D:/STM32F407_Firmware/Driver/USART" -I"D:/STM32F407_Firmware/Driver/SPI" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CAN

clean-CAN:
	-$(RM) ./CAN/CAN.cyclo ./CAN/CAN.d ./CAN/CAN.o ./CAN/CAN.su

.PHONY: clean-CAN

