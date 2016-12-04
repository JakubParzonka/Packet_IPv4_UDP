################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/funkcje.c \
../src/kopiuj_i_wyswietl.c \
../src/main.c 

OBJS += \
./src/funkcje.o \
./src/kopiuj_i_wyswietl.o \
./src/main.o 

C_DEPS += \
./src/funkcje.d \
./src/kopiuj_i_wyswietl.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


