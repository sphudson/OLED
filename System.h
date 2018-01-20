
/*! 
 *  Copyright (c) 2012, Stanford P. Hudson, All Rights Reserved
 * 
 *  @file System.h
 *  @brief System header file
*/

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "Common.h"
#include <msp430f2013.h>

#define SYSTEM_MCLK_FREQ_HZ      (16000000ul) /* Hz */
#define SYSTEM_CLOCK_DIVISOR     (1)

#define SYSTEM_DELAY_SECS(_x)    __delay_cycles((u32_t)_x * SYSTEM_MCLK_FREQ_HZ)
#define SYSTEM_DELAY_MSECS(_x)   __delay_cycles((u32_t)_x * (SYSTEM_MCLK_FREQ_HZ / 1000ul))

void SystemInit(void);
void SystemShutdown(void);

#endif
