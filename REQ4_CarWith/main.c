/*
 * REQ3_Car_PWM
 *
 * Created: 10/28/2019 4:37:18 PM
 * Author : Ammar Shahin
 */ 

#include "t_typedef.h"
#include "gpio.h"
#include "interrupt_Lib.h"
#include "timer_LCFG.h"
#include "timers.h"
#include "ICU.h"
#include "led.h"
#include <util/delay.h>


void MOTOR_FORWARD(void){
	Av_gpioPinWrite(myPORTA , BIT4 , HIGH);
	Av_gpioPinWrite(myPORTA , BIT5 , LOW);
	Av_gpioPinWrite(myPORTA , BIT6 , HIGH);
	Av_gpioPinWrite(myPORTA , BIT7 , LOW);
}

void MOTOR_BACK(void){
	Av_gpioPinWrite(myPORTA , BIT4 , LOW);
	Av_gpioPinWrite(myPORTA , BIT5 , HIGH);
	Av_gpioPinWrite(myPORTA , BIT6 ,  LOW);
	Av_gpioPinWrite(myPORTA , BIT7 , HIGH);
}

void MOTOR_ROTATE(void){// rotate 90 clockwise
	Av_gpioPinWrite(myPORTA , BIT4 , LOW);
	Av_gpioPinWrite(myPORTA , BIT5 , HIGH);
	Av_gpioPinWrite(myPORTA , BIT6 , HIGH);
	Av_gpioPinWrite(myPORTA , BIT7 ,  LOW);
}

void MOTOR_STOP(void)
{
	Av_gpioPinWrite(myPORTA , BIT4 , LOW);
	Av_gpioPinWrite(myPORTA , BIT5 , LOW);
	Av_gpioPinWrite(myPORTA , BIT6 , LOW);
	Av_gpioPinWrite(myPORTA , BIT7 , LOW);
}

int main(void)
{
	uint16 distance = 50;
	Av_gpioPortDirection(myPORTA,set_OUT); // setting PORTA to be all output   
	Av_gpioPortDirection(myPORTC,set_OUT);	// setting PORTC to be all output
	
	Av_gpioPinDirection(myPORTD,BIT2,set_IN);
	Av_gpioPinDirection(myPORTD,BIT5,set_OUT);
	
	led_Init(LED0);
	led_Init(LED1);
	
	Av_ICU_Init();
	
	Av_timer1Init(T1_PWM_PhaseCorrect_ICR1_MODE,T1_OC1A_CLEAR,T1_PRESCALER_1024,0,0,0,0,T1_POLLING);
	Av_timer1Start();
	AVE_timer1PWM(50,500);
	
/* Initializing the timer zero using linking configuration */
	Timer_Init(&cfg_s);
	Timer_Start(TIMER0);
	
	while (1) 
    {
		Av_UltraSonicTrigger();
		distance = Av_UltraSonicDistanc();
		
		if(distance < 30)
		{
			AVE_timer1PWM(50,500); // Slowing down the speed while rotating
			MOTOR_ROTATE();
			_delay_ms(200);
			led_On(LED0);
			led_Off(LED1);
		}
		else if(distance > 30)
		{
			AVE_timer1PWM(100,500);
			MOTOR_FORWARD();
			led_Off(LED0);
			led_On(LED1);
		}
	}
}