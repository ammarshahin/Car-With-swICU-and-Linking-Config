/*
 * ICU.c
 *
 * Created: 10/28/2019 3:45:51 PM
 *  Author: Ammar Shahin
 */ 

#include "t_typedef.h"
#include "interrupt_Lib.h"
#include "gpio.h"
#include "timers.h"
#include "ICU.h"
#include <util/delay.h>

volatile uint8 flag = 0,numOfOverflows = 0;
volatile uint64 raising_time_ns = 0;


t_ISR(INT0_vect)
{
	if(flag == 0)
	{
		TCNT2 = 0;
		Av_timer2Start();
		numOfOverflows = 0;
		flag = 1;
	}
	else if(flag == 1)
	{
		raising_time_ns =  ( ( (numOfOverflows * 256) + TCNT2 ) * ( 1000000000/F_CPU ) );
		Av_timer1Stop();
		numOfOverflows = 0;
		TCNT2 = 0;
		flag = 0;
	}
}

t_ISR(TIMER2_OVF_vect)
{
	numOfOverflows++;
}

uint32 Av_UltraSonicDistanc()
{
	uint32 theDistance;
	theDistance = ( (raising_time_ns/1000000000.0) * (34300/2) );
	return theDistance;
}

void Av_ICU_Init()
{
	INT0_Init_anyChange();
	Av_timer2Init(T2_NORMAL_MODE,T2_OC0_DIS,T2_PRESCALER_1,0,0,T2_INTERRUPT_NORMAL);
	interrupts_On();
}

void Av_UltraSonicTrigger()
{
	Av_gpioPinWrite(myPORTA,BIT0,HIGH);
	_delay_us(15);
	Av_gpioPinWrite(myPORTA,BIT0,LOW);	
}