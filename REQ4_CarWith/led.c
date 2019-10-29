/*
 * led.c
 *
 *  Created: 10/21/2019 6:37:05 PM
 *  Author: Ammar Shahin
 */ 

#include "t_typedef.h"
#include "ledConfig.h"
#include "led.h"
#include "gpio.h"

/*===========================Led Control Functions===============================*/
/**
 * Description: Initilizing Function to the Led
 * @param led_Num the number of the Led [LED0,LED1,LED2,LED3]
 */
void led_Init(led led_Num)
{
	switch(led_Num)
	{
		case LED0 :
		Av_gpioPinDirection(LED_PORT,LED0,set_OUT);
		Av_gpioPinWrite(LED_PORT,LED0,FALSE);
		break;
		case LED1 :
		Av_gpioPinDirection(LED_PORT,LED1,set_OUT);
		Av_gpioPinWrite(LED_PORT,LED1,FALSE);
		break;
		case LED2 :
		Av_gpioPinDirection(LED_PORT,LED2,set_OUT);
		Av_gpioPinWrite(LED_PORT,LED2,FALSE);
		break;
		case LED3 :
		Av_gpioPinDirection(LED_PORT,LED3,set_OUT);
		Av_gpioPinWrite(LED_PORT,LED3,FALSE);
		break;
		default:
		break;
	}
}

/**
 * Description: Function to set the Led to On
 * @param led_Num the number of the Led [LED0,LED1,LED2,LED3]
 */
void led_On(led led_Num)
{
	switch(led_Num)
	{
		case LED0 :
		Av_gpioPinWrite(LED_PORT,LED0,TRUE);
		break;
		case LED1 :
		Av_gpioPinWrite(LED_PORT,LED1,TRUE);
		break;
		case LED2 :
		Av_gpioPinWrite(LED_PORT,LED2,TRUE);
		break;
		case LED3 :
		Av_gpioPinWrite(LED_PORT,LED3,TRUE);
		break;
		default:
		break;
	}
}

/**
 * Description: Function to set the Led to Off.
 * @param led_Num the number of the Led [LED0,LED1,LED2,LED3].
 */
void led_Off(led led_Num)
{
	switch(led_Num)
	{
		case LED0 :
		Av_gpioPinWrite(LED_PORT,LED0,FALSE);
		break;
		case LED1 :
		Av_gpioPinWrite(LED_PORT,LED1,FALSE);
		break;
		case LED2 :
		Av_gpioPinWrite(LED_PORT,LED2,FALSE);
		break;
		case LED3 :
		Av_gpioPinWrite(LED_PORT,LED3,FALSE);
		break;
		default:
		break;
	}
}

/**
 * Description: Function to Toggle the Led.
 * @param led_Num the number of the Led [LED0,LED1,LED2,LED3]
 */
void led_Tog(led led_Num)
{
	switch(led_Num)
	{
		case LED0 :
		Av_gpioPinToggle(LED_PORT,LED0);
		break;
		case LED1 :
		Av_gpioPinToggle(LED_PORT,LED1);
		break;
		case LED2 :
		Av_gpioPinToggle(LED_PORT,LED2);
		break;
		case LED3 :
		Av_gpioPinToggle(LED_PORT,LED3);
		break;
		default:
		break;
	}
}