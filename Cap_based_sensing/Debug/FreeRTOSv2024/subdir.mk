################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOSv2024/croutine.c \
../FreeRTOSv2024/list.c \
../FreeRTOSv2024/queue.c \
../FreeRTOSv2024/stream_buffer.c \
../FreeRTOSv2024/tasks.c \
../FreeRTOSv2024/timers.c 

OBJS += \
./FreeRTOSv2024/croutine.o \
./FreeRTOSv2024/list.o \
./FreeRTOSv2024/queue.o \
./FreeRTOSv2024/stream_buffer.o \
./FreeRTOSv2024/tasks.o \
./FreeRTOSv2024/timers.o 

C_DEPS += \
./FreeRTOSv2024/croutine.d \
./FreeRTOSv2024/list.d \
./FreeRTOSv2024/queue.d \
./FreeRTOSv2024/stream_buffer.d \
./FreeRTOSv2024/tasks.d \
./FreeRTOSv2024/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOSv2024/%.o FreeRTOSv2024/%.su FreeRTOSv2024/%.cyclo: ../FreeRTOSv2024/%.c FreeRTOSv2024/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I"D:/MUC2/Cap_based_sensing/FreeRTOSv2024" -I"D:/MUC2/Cap_based_sensing/FreeRTOSv2024/include" -I"D:/MUC2/Cap_based_sensing/FreeRTOSv2024/portable/GCC/ARM_CM4F" -I"D:/MUC2/Cap_based_sensing/FreeRTOSv2024/portable/MemMang" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-FreeRTOSv2024

clean-FreeRTOSv2024:
	-$(RM) ./FreeRTOSv2024/croutine.cyclo ./FreeRTOSv2024/croutine.d ./FreeRTOSv2024/croutine.o ./FreeRTOSv2024/croutine.su ./FreeRTOSv2024/list.cyclo ./FreeRTOSv2024/list.d ./FreeRTOSv2024/list.o ./FreeRTOSv2024/list.su ./FreeRTOSv2024/queue.cyclo ./FreeRTOSv2024/queue.d ./FreeRTOSv2024/queue.o ./FreeRTOSv2024/queue.su ./FreeRTOSv2024/stream_buffer.cyclo ./FreeRTOSv2024/stream_buffer.d ./FreeRTOSv2024/stream_buffer.o ./FreeRTOSv2024/stream_buffer.su ./FreeRTOSv2024/tasks.cyclo ./FreeRTOSv2024/tasks.d ./FreeRTOSv2024/tasks.o ./FreeRTOSv2024/tasks.su ./FreeRTOSv2024/timers.cyclo ./FreeRTOSv2024/timers.d ./FreeRTOSv2024/timers.o ./FreeRTOSv2024/timers.su

.PHONY: clean-FreeRTOSv2024

