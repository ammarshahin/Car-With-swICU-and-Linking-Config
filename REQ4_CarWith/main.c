/*
 * REQ3_Car_PWM
 *
 * Created: 10/28/2019 4:37:18 PM
 * Author : Ammar Shahin
 */ 

#include "t_typedef.h"
#include "gpio.h"
#include "interrupt_Lib.h"
#include "timers.h"
#include "swPWM.h"
#include "ICU.h"
#include "led.h"


void MOTOR_FORWARD(void){
	Av_gpioPinWrite(myPORTA , BIT4 , HIGH);
	Av_gpioPinWrite(myPORTA , BIT5 , LOW);
	Av_gpioPinWrite(myPORTA , BIT6 , HIGH);
	Av_gpioPinWrite(myPORTA , BIT7 , LOW);
	//AVE_timer1PWM(90,50);
}

void MOTOR_BACK(void){
	Av_gpioPinWrite(myPORTA , BIT4 , LOW);
	Av_gpioPinWrite(myPORTA , BIT5 , HIGH);
	Av_gpioPinWrite(myPORTA , BIT6 ,  LOW);
	Av_gpioPinWrite(myPORTA , BIT7 , HIGH);
	//AVE_timer1PWM(50,50);
}

void MOTOR_ROTATE(void){// rotate 90 clockwise
	Av_gpioPinWrite(myPORTA , BIT4 , LOW);
	Av_gpioPinWrite(myPORTA , BIT5 , HIGH);
	Av_gpioPinWrite(myPORTA , BIT6 , HIGH);
	Av_gpioPinWrite(myPORTA , BIT7 ,  LOW);
	//AVE_timer1PWM(50,50);
}

void MOTOR_STOP()
{
	Av_gpioPinWrite(myPORTA , BIT4 , LOW);
	Av_gpioPinWrite(myPORTA , BIT5 , LOW);
	Av_gpioPinWrite(myPORTA , BIT6 , LOW);
	Av_gpioPinWrite(myPORTA , BIT7 , LOW);
	//AVE_timer1PWM(10,50);
}

int main(void)
{
	volatile uint16 distance = 50;
	Av_gpioPortDirection(myPORTA,set_OUT);
	Av_gpioPortDirection(myPORTC,set_OUT);
	Av_gpioPinDirection(myPORTD,BIT2,set_IN);
	Av_gpioPinDirection(myPORTD,BIT5,set_OUT);
	Av_ICU_Init();
	Av_timer1Init(T1_PWM_PhaseCorrect_ICR1_MODE,T1_OC1A_CLEAR,T1_PRESCALER_1024,0,0,0,0,T1_POLLING);
	Av_timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_1,0,0,T0_POLLING);
	Av_timer1Start();
	Av_timer0Start();
	led_Init(LED0);
	led_Init(LED1);
	//AVE_timer1PWM(50,500);
	while (1) 
    {
		Av_UltraSonicTrigger();
		distance = Av_UltraSonicDistanc();
		if(distance < 30)
		{
			//AVE_timer1PWM(1,500);
			//MOTOR_STOP();
			//Av_timer0Start();
			//Av_timer0Delay_ms(100);
			//Av_timer0Stop();
			//AVE_timer1PWM(30,500);
			//MOTOR_BACK();
			AVE_timer1PWM(20,500);
			MOTOR_ROTATE();
			Av_timer0Delay_ms(100);
			led_On(LED0);
			led_Off(LED1);
		}
		else if(distance > 30)
		{
			AVE_timer1PWM(50,500);
			MOTOR_FORWARD();
			//Av_timer0Delay_ms(100);
			led_Off(LED0);
			led_On(LED1);
		}else
		{
			//AVE_timer1PWM(70,500);
		}
	}
}