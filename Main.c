
/*! 
 *  Copyright (c) 2012, Stanford P. Hudson, All Rights Reserved
 *
 *  @file Main.c
 *  @brief Main C entry point module
*/

#include "Common.h"
#include "Main.h"
#include "System.h"
#include "App.h"

/*!
 * @brief Main C entry point function
 */
void main(void)
{   
  /* initialize peripherals and device drivers */
  SystemInit();
  
  /* initialize application */
  AppInit();
  
  /* jump to main application */
  AppMain();
  
  /* shutdown system */
  SystemShutdown();
}

