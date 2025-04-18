/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include<stdint.h>
#include "main.h"
int main(void)
{
	/*
	 * uint32_t *pClkCtrlReg =   (uint32_t*)0x40023830;
	 * uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
	 * uint32_t *pPortDOutReg =  (uint32_t*)0x40020C14;
	 */
	RCC_AHB1ENR_t volatile *const pClkCtrlReg = ADDR_REG_AHB1ENR;
	GPIOx_MODE_t volatile *const pPortDModeReg = ADDR_REG_GPIOD_MODE;
	GPIOx_ODR_t volatile *const pPortDOutReg = ADDR_REG_GPIOD_OD;

	// 1. enable the clock for GPOID peripheral in the AHB1ENR (SET the 3rd bit position)
	// *pClkCtrlReg |= ( 1 << 3);

	pClkCtrlReg->gpiod_en = CLOCK_ENABLE;

	// 2. configure the mode of the IO pin as output
	// a. clear the 24th and 25th bit positions (CLEAR)
	// *pPortDModeReg &= ~( 3 << 24);
	// b. make 24th bit position as 1 (SET)
	// *pPortDModeReg |= ( 1 << 24);

	pPortDModeReg->pin_12 = MODE_OUTPUT;

	while(1){
		// 3.SET 12th bit of the output data register to make I/O pin-12 as HIGH
		// *pPortDOutReg |= ( 1 << 12);

		pPortDOutReg->pin_12 = PIN_STATE_HIGH;

		// Introduce small observable delay
		for(uint32_t i = 0; i < DELAY_COUNT; i++);

		// Turn off the LED
		// *pPortDOutReg &= ~(1 << 12);

		pPortDOutReg->pin_12 = PIN_STATE_LOW;

		for(uint32_t i = 0; i < DELAY_COUNT; i++);
	}

}
