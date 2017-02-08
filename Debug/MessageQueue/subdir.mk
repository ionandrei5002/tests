################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../MessageQueue/Bus.cpp \
../MessageQueue/Queue.cpp 

OBJS += \
./MessageQueue/Bus.o \
./MessageQueue/Queue.o 

CPP_DEPS += \
./MessageQueue/Bus.d \
./MessageQueue/Queue.d 


# Each subdirectory must supply rules for building sources it contributes
MessageQueue/%.o: ../MessageQueue/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


