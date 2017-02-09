################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Game.cpp \
../GameBall.cpp \
../MainMenu.cpp \
../PlayerPaddler.cpp \
../SplashScreen.cpp \
../VisibleGameObject.cpp \
../main.cpp 

OBJS += \
./Game.o \
./GameBall.o \
./MainMenu.o \
./PlayerPaddler.o \
./SplashScreen.o \
./VisibleGameObject.o \
./main.o 

CPP_DEPS += \
./Game.d \
./GameBall.d \
./MainMenu.d \
./PlayerPaddler.d \
./SplashScreen.d \
./VisibleGameObject.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


