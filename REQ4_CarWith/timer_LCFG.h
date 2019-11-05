/*
 * timer_LCFG.h
 *
 * Created: 11/4/2019 2:04:00 PM
 *  Author: Ammar Shahin
 */ 
#ifndef   _TIMER_LCFG_H
#define  _TIMER_LCFG_H

#include "t_typedef.h"

#define TIMER0  0
#define TIMER1  1
#define TIMER2  2

#define TIMER_MODE    0
#define Counter_MODE  1

#define INTERRUPT     1
#define POLLING       0

typedef struct Timer_CFG_S{
	uint8  ch_no;
	uint8  Timer_Mode;
	uint16 TIMER_count;
	uint8  Timer_Interrupt;
	uint32 CPU_CLK;
}Timer_CFG_S;

extern Timer_CFG_S cfg_s;

#endif /* _TIMER_LCFG_H */