################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/copy.c \
../src/display.c \
../src/linked_list.c \
../src/main.c \
../src/send.c 

OBJS += \
./src/copy.o \
./src/display.o \
./src/linked_list.o \
./src/main.o \
./src/send.o 

C_DEPS += \
./src/copy.d \
./src/display.d \
./src/linked_list.d \
./src/main.d \
./src/send.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


