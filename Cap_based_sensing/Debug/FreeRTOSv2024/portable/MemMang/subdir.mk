################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOSv2024/portable/MemMang/heap_4.c 

OBJS += \
./FreeRTOSv2024/portable/MemMang/heap_4.o 

C_DEPS += \
./FreeRTOSv2024/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOSv2024/portable/MemMang/%.o FreeRTOSv2024/portable/MemMang/%.su FreeRTOSv2024/portable/MemMang/%.cyclo: ../FreeRTOSv2024/portable/MemMang/%.c FreeRTOSv2024/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"D:/MUC2/Cap_based_sensing/FreeRTOSv2024" -I"D:/MUC2/Cap_based_sensing/FreeRTOSv2024/include" -I"D:/MUC2/Cap_based_sensing/FreeRTOSv2024/portable/GCC/ARM_CM4F" -I"D:/MUC2/Cap_based_sensing/FreeRTOSv2024/portable/MemMang" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-FreeRTOSv2024-2f-portable-2f-MemMang

clean-FreeRTOSv2024-2f-portable-2f-MemMang:
	-$(RM) ./FreeRTOSv2024/portable/MemMang/heap_4.cyclo ./FreeRTOSv2024/portable/MemMang/heap_4.d ./FreeRTOSv2024/portable/MemMang/heap_4.o ./FreeRTOSv2024/portable/MemMang/heap_4.su

.PHONY: clean-FreeRTOSv2024-2f-portable-2f-MemMang

