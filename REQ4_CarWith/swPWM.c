/*
 * swPWM.c
 *
 * Created: 10/23/2019 8:10:07 PM
 *  Author: Ammar Shahin
 */ 

#include "t_typedef.h"
#include "timers.h"
#include "gpio.h"
#include "swPWM.h"


/**
 * Description: Av_timer0SwPWM is a function to generate a software PWM on a GPIO pin 
			the freq, port, and the pin of the output in the timers.h 
 * @param dutyCycle : the duty cycle of the PWM in percentage
 */
void Av_SwPWM(uint8 dutyCycle, uint32 freq,uint8 output_PORT,uint8 output_PIN)
{
	uint32 time_Total_ns = (1000000000.0 / freq);
	uint32 time_On_ns  = (dutyCycle * time_Total_ns/100);
	uint32 time_Off_ns = time_Total_ns - time_On_ns;
	//switch(timer_Number)
	//{
		//case TIMER_0 : 
		Av_gpioPinDirection(output_PORT,output_PIN,set_OUT);
		//while(1)
		//{
			Av_gpioPinWrite(output_PORT,output_PIN,TRUE);
			Av_timer0Delay_ns(time_On_ns);
			Av_gpioPinWrite(output_PORT,output_PIN,FALSE);
			Av_timer0Delay_ns(time_Off_ns);
		//}
		//break;
		//case TIMER_1 :
		//Av_gpioPinDirection(output_PORT,output_PIN,set_OUT);
		////while(1)
		////{
			//Av_gpioPinWrite(output_PORT,output_PIN,TRUE);
			//Av_timer1Delay_ns(time_On_ns);
			//Av_gpioPinWrite(output_PORT,output_PIN,FALSE);
			//Av_timer1Delay_ns(time_Off_ns);
		////}
		//case TIMER_2 :
		//Av_gpioPinDirection(output_PORT,output_PIN,set_OUT);
		////while(1)
		////{
			//Av_gpioPinWrite(output_PORT,output_PIN,TRUE);
			//Av_timer2Delay_ns(time_On_ns);
			//Av_gpioPinWrite(output_PORT,output_PIN,FALSE);
			//Av_timer2Delay_ns(time_Off_ns);
		////}
		//break;
	//}
}


