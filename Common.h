
/*! 
 *  Copyright (c) 2012, Stanford P. Hudson, All Rights Reserved
 *
 *  @file Common.h
 *  @brief Common header file
*/

#ifndef _COMMON_H_
#define _COMMON_H_

typedef unsigned long      u32_t;
typedef signed long        s32_t;
typedef unsigned int       u16_t;
typedef signed int         s16_t;
typedef unsigned char      u8_t;
typedef signed char        s8_t;
typedef unsigned char      bool;

#define TRUE               (1)
#define FALSE              (0)
#define ON                 (1)
#define OFF                (0)

#define Abs(x)             ((((s16_t)(x)) < 0) ? -(x): (x))

#endif
