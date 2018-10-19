################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables
ASM_SRCS += \
../generate/cstart.asm 

ASSEMBLER_OBJS += \
generate/cstart.obj 

ASM_DEPS += \
generate/cstart.d 

# Each subdirectory must supply rules for building sources it contributes
generate/%.obj: ../generate/%.asm 
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Assembler'
	ccrl -asmopt=-MM -asmopt=-MP -asmopt=-MF="$(@:%.obj=%.d)" -asmopt=-MT="$(@:%.obj=%.obj)" -asmopt=-MT="$(@:%.obj=%.d)" -cpu=S1 -c -dev="C:\Renesas\e2_studio\eclipse\\..\\DebugComp\\RL78\RL78\Common\DR5F10Y16.DVF" -msg_lang=japanese  "$<"
	ccrl -cpu=S1 -c -dev="C:\Renesas\e2_studio\eclipse\\..\\DebugComp\\RL78\RL78\Common\DR5F10Y16.DVF" -msg_lang=japanese -g -o "$(@:%.d=%.obj)" "$<"
	@echo 'Finished Scanning and building: $<'
	@echo.

