
/*! 
 *  Copyright (c) 2012, Stanford P. Hudson, All Rights Reserved
 *
 *  @file System.c
 *  @brief System module
*/

#include <msp430f2013.h>
#include "Common.h"
#include "System.h"

/*!
 * @brief Main system initialization function.  This function
 *        initializes the clock, timers, ADC, flash, and other peripherals.
 */
void SystemInit(void)
{    
  /* setup DCO */
  BCSCTL1 = CALBC1_16MHZ;
  DCOCTL = CALDCO_16MHZ;
  
  /* initialize device modules */
  
  USICTL0 |= USIPE6 + USIPE5 + USIMST + USIOE;
  USICTL1 |= USIIE;
  USICKCTL = USIDIV_1 + USISSEL_2 + USICKPL;
  USICTL0 &= ~USISWRST;
}

/*!
 * @brief Disables interrupts, puts external devices to sleep, and
 *        places the processor into sleep mode
 */
void SystemShutdown(void)
{
  __disable_interrupt();
  for (;;)
  {
    LPM4;
  }
}

/*!
 * @brief This function is called before main() and any C
 *        initialization.  It is designed to allow the watchdog
 *        to be stopped quickly after power-up and also to setup
 *        I/O pins and other peripherals to their default state.
 * @retval 1 successful initialization
 */
int _system_pre_init()
{
  /* stop watchdog */
  WDTCTL = WDTPW + WDTHOLD;

  __disable_interrupt();

  /* setup port 1 */
  P1SEL = BIT5 + BIT6;
  P1OUT = BIT0 + BIT1 + BIT2;
  P1DIR = BIT0 + BIT1 + BIT2 + BIT5 + BIT6;
  P1REN = 0;
  P1IE = 0;
  P1IES = 0; 
  P1IFG = 0;
    
  /* setup port 2 */
  P2SEL = 0;
  P2OUT = 0;
  P2DIR = 0;
  P2REN = 0;
  P2IE = 0;
  P2IES = 0;
  P2IFG = 0;

  return 1;
}
