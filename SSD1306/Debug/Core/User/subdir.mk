################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/User/ssd1306.c \
../Core/User/ssd1306_fonts.c \
../Core/User/ssd1306_tests.c 

OBJS += \
./Core/User/ssd1306.o \
./Core/User/ssd1306_fonts.o \
./Core/User/ssd1306_tests.o 

C_DEPS += \
./Core/User/ssd1306.d \
./Core/User/ssd1306_fonts.d \
./Core/User/ssd1306_tests.d 


# Each subdirectory must supply rules for building sources it contributes
Core/User/%.o Core/User/%.su Core/User/%.cyclo: ../Core/User/%.c Core/User/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Core/User -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-User

clean-Core-2f-User:
	-$(RM) ./Core/User/ssd1306.cyclo ./Core/User/ssd1306.d ./Core/User/ssd1306.o ./Core/User/ssd1306.su ./Core/User/ssd1306_fonts.cyclo ./Core/User/ssd1306_fonts.d ./Core/User/ssd1306_fonts.o ./Core/User/ssd1306_fonts.su ./Core/User/ssd1306_tests.cyclo ./Core/User/ssd1306_tests.d ./Core/User/ssd1306_tests.o ./Core/User/ssd1306_tests.su

.PHONY: clean-Core-2f-User

