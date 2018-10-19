################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
C_SRCS += \
../src/cg_src/r_cg_cgc.c \
../src/cg_src/r_cg_cgc_user.c \
../src/cg_src/r_cg_intp.c \
../src/cg_src/r_cg_intp_user.c \
../src/cg_src/r_cg_main.c \
../src/cg_src/r_cg_systeminit.c \
../src/cg_src/r_cg_tau.c \
../src/cg_src/r_cg_tau_user.c 

COMPILER_OBJS += \
src/cg_src/r_cg_cgc.obj \
src/cg_src/r_cg_cgc_user.obj \
src/cg_src/r_cg_intp.obj \
src/cg_src/r_cg_intp_user.obj \
src/cg_src/r_cg_main.obj \
src/cg_src/r_cg_systeminit.obj \
src/cg_src/r_cg_tau.obj \
src/cg_src/r_cg_tau_user.obj 

C_DEPS += \
src/cg_src/r_cg_cgc.d \
src/cg_src/r_cg_cgc_user.d \
src/cg_src/r_cg_intp.d \
src/cg_src/r_cg_intp_user.d \
src/cg_src/r_cg_main.d \
src/cg_src/r_cg_systeminit.d \
src/cg_src/r_cg_tau.d \
src/cg_src/r_cg_tau_user.d 

# Each subdirectory must supply rules for building sources it contributes
src/cg_src/%.obj: ../src/cg_src/%.c 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	ccrl -MM -MP -o "$(@:%.obj=%.d)"  -MT="$(@:%.obj=%.obj)"  -MT="$(@:%.obj=%.d)" -cpu=S1  -dev="C:\Renesas\e2_studio\eclipse\\..\\DebugComp\\RL78\RL78\Common\DR5F10Y16.DVF" -msg_lang=japanese -I "C:\PROGRA~2\Renesas\RL78\1_6_0\inc","C:\Users\YOSHINORI\e2_studio\workspace\AutoNightDimmingLedLight\generate","C:\Users\YOSHINORI\e2_studio\workspace\AutoNightDimmingLedLight\src" -lang=c  "$<"
	ccrl -cpu=S1 -c -dev="C:\Renesas\e2_studio\eclipse\\..\\DebugComp\\RL78\RL78\Common\DR5F10Y16.DVF" -msg_lang=japanese -I "C:\PROGRA~2\Renesas\RL78\1_6_0\inc","C:\Users\YOSHINORI\e2_studio\workspace\AutoNightDimmingLedLight\generate","C:\Users\YOSHINORI\e2_studio\workspace\AutoNightDimmingLedLight\src" -lang=c -g -o "$(@:%.d=%.obj)" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

