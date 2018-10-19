/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2012, 2017 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_tau_user.c
* Version      : Code Generator for RL78/G10 V1.05.01.01 [08 Nov 2017]
* Device(s)    : R5F10Y16
* Tool-Chain   : CCRL
* Description  : This file implements device driver for TAU module.
* Creation Date: 2018/10/19
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_tau.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_tau0_channel0_interrupt(vect=INTTM00)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_tau0_channel0_interrupt
* Description  : This function INTTM00 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_tau0_channel0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */

	uint32_t DutyCycle; // 0=0%, 19999=100%

	WakeUpTime1MS++;

	if(WakeUpTime1MS < 3000)
	{// Less than 3 second, brighten slowly
		Status = Brighten;
		DutyCycle = 19999 * WakeUpTime1MS / 2999;
        DI();
        TDR01H = (DutyCycle&0xFF00)>>8;
        TDR01L = (DutyCycle&0x00FF)>>0;
        EI();
	}
	else if(WakeUpTime1MS < (5UL * 60 * 1000))
	{// Wait for 5 minutes
		Status = Wait;
	}
	else if(WakeUpTime1MS < (5UL * 60 * 1000 + 3000))
	{// After 5 minutes, darken slowly
		Status = Darken;
		DutyCycle = 19999 * (WakeUpTime1MS-(5UL * 60 * 1000)) / 2999;
		DutyCycle = 19999 - DutyCycle; // invert
        DI();
        TDR01H = (DutyCycle&0xFF00)>>8;
        TDR01L = (DutyCycle&0x00FF)>>0;
        EI();
	}
	else
	{//The end of the sequence
		R_TAU0_Channel0_Stop();
		Status = Sleep;
	}
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
