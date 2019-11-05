/*
 * timers.c
 *
 * Created: 10/22/2019 2:04:00 PM
 *  Author: Ammar Shahin
 */ 

#include "t_typedef.h"
#include "gpio.h"
#include "timer_LCFG.h"
#include "timers.h"


volatile uint16 preScaller_TIMER0;
volatile uint16 preScaller_TIMER1;
volatile uint16 preScaller_TIMER2;

volatile uint8 prescaller0 = 0x05; // set the prescaler to 1024
volatile uint8 prescaller1 = 0;
volatile uint8 prescaller2 = 0;

volatile uint32 gv_F_CPU;
volatile uint8 gv_Count;


/************************************************************************/
/*                   Timers' Functions' Implementations                 */
/************************************************************************/



/**
 * Description: this function is to initialize the Timer0 
 * @param cfg_s the Configuration Structure which include:
 * 								1- the Channel of the Timer(Timer0,Timer1,Timer2)
 *								2- the mode(Timer or counter)
 * 								3- the amount of counters that the timer has to wait before in MS
 * 								4- the interrupt mask
 * @return the Status of the initialization [1 for success and 0 for failure] 
 */
uint8 Timer_Init(Timer_CFG_S* cfg_s)
{
		uint8 prescal;
		uint32 no_Of_Count;
		gv_F_CPU = cfg_s->CPU_CLK;
		switch (cfg_s->ch_no)
		{
			case TIMER0:
						TCCR0 |= cfg_s->Timer_Mode;
						TIMSK |= cfg_s->Timer_Interrupt;
						prescal = prescaller0; 
						switch(prescal)
						{
							case 0 :
							preScaller_TIMER0= 0;
							break;
							case  1 :
							preScaller_TIMER0= 1;
							break;
							case  2 :
							preScaller_TIMER0= 8;
							break;
							case  3 :
							preScaller_TIMER0= 64;
							break;
							case  4 :
							preScaller_TIMER0= 256;
							break;
							case  5 :
							preScaller_TIMER0= 1024;
							break;
						}
						no_Of_Count = ( cfg_s->TIMER_count / 128);
						if(no_Of_Count > 254)
						{
							return 0;
						}
						else
						{
						gv_Count = 265 - no_Of_Count;
						TCNT0 = gv_Count;
						}
			break;
			case TIMER1:				
			break;
			case TIMER2:	
			break;
			default:
			break;
		}
		return 1;
}




/**
 * Description: Function to set the timer Reg with a value
 * @param value the value to set 
 */
uint8 Timer_set_counter(uint8 ch_no,uint16 count)
{
	uint32 no_Of_Count;
	switch (ch_no)
	{
	case TIMER0:
		no_Of_Count = ( count / 128);
		if(no_Of_Count > 254)
		{
			return 0;
		}
		else
		{
			gv_Count = 265 - no_Of_Count;
			TCNT0 = gv_Count;
		}
		break;
	case TIMER1:
		break;
	case TIMER2:
		break;
	default:
		break;
	}
	return 1;
}

/**
 * Description: start the counter/Timer
 */
uint8 Timer_Start(uint8 ch_no)
{
	switch (ch_no)
	{
	case TIMER0:
		TCCR0 = ( (TCCR0 & 0xf8) | prescaller0);
		break;
	case TIMER1:
		break;
	case TIMER2:
		break;
	default:
		break;
	}
	return 1;
}


/**
 * Description: Stop the Timer/Counter by setting the the prescaler pins to 0
 */
uint8 Timer_Stop(uint8 ch_no)
{
	switch (ch_no)
	{
	case TIMER0:
		TCCR0 &= ~(0x07);
		break;
	case TIMER1:
		break;
	case TIMER2:
		break;
	default:
		break;
	}
	return 1;
}


/**
 * Description: Read the Timer/Counter Refister
 */
uint32 Timer_Read(uint8 ch_no)
{
	switch (ch_no)
	{
	case TIMER0:
		return TCNT0;
		break;
	case TIMER1:
		break;
	case TIMER2:
		break;
	default:
		break;
	}
	return 0;
}









///*===========================Timer0 Control===============================*/
///**
 //* Description: this function is to initialize the Timer0 
 //* @param control the control Reg value which include the mode and the preScaller_TIMER0
 //* @param initialValue the initial value to be set in the TCNT0 Reg
 //* @param outputCompare the value to be set in the OCR0 Reg 
 //* @param interruptMask Enable or disable the interrupts of the Timer
 //*/
//void Av_timer0Init(T0_MODE mode,T0_COM OC0,T0_PRESCALER prescal, uint8 initialValue, uint8 outputCompare, T0_INTERRUPT interruptMask)
//{
	//TCCR0 |= (mode|OC0);
	//TCNT0 = initialValue;
	//OCR0  = outputCompare;
	//TIMSK |= interruptMask;
	//prescaller0 = prescal;
		//switch(prescal)
		//{
			//case T0_NO_CLOCK :
			//preScaller_TIMER0= 0;
			//break;
			//case  T0_PRESCALER_1 :
			//preScaller_TIMER0= 1;
			//break;
			//case  T0_PRESCALER_8 :
			//preScaller_TIMER0= 8;
			//break;
			//case  T0_PRESCALER_64 :
			//preScaller_TIMER0= 64;
			//break;
			//case  T0_PRESCALER_256 :
			//preScaller_TIMER0= 256;
			//break;
			//case  T0_PRESCALER_1024 :
			//preScaller_TIMER0= 1024;
			//break;
		//}
//}
//
///**
 //* Description: Function to set the timer Reg with a value
 //* @param value the value to set 
 //*/
//void Av_timer0Set(uint8 value)
//{
	//TCNT0 = value;
//}
//
///**
 //* Description: read the value of the TCNT0 Register
 //* @return return the value
 //*/
//uint8 Av_timer0Read(void)
//{
	//return TCNT0;
//}
//
///**
 //* Description: start the counter/Timer
 //*/
//void Av_timer0Start(void)
//{
	//TCCR0 |= prescaller0;
//
//}
//
//
///**
 //* Description: Stop the Timer/Counter by setting the the prescaller pins to 0
 //*/
//void Av_timer0Stop(void)
//{
	//TCCR0 &= ~(0x07);
//}
//
///**
 //* Description: Delay function pooling based to block the code for a specific amount of time
 //* @param delay the time I want to delay in ms
 //*/
//void Av_timer0Delay_ms(uint16 delay)
//{
	//volatile sint64 counter = ((sint64)delay) * F_CPU / (256.0 * preScaller_TIMER0 * 1000.0);
	//TCNT0 = 0;
	//Av_timer0Start();
	//while(counter-- > 0)
	//{
		//while( (TIFR & 0x01) == 0);
		//TIFR |= 0x01;
	//}
	//Av_timer0Stop();
//}
//
//
//
///**
 //* Description: Delay function pooling based to block the code for a specific amount of time
 //* @param delay the time I want to delay in ns
 //*/
//void Av_timer0Delay_ns(uint32 delay)
//{
	//volatile sint64 counter = ((uint64) delay) * F_CPU / (256.0 * preScaller_TIMER0 * 1000000000.0);
	//Av_timer0Start();
	//while(counter-- > 0)
	//{
		//while( (TIFR & 0x01) == 0);
		//TIFR |= 0x01;
	//}
	//Av_timer0Stop();
//}
//
///**
 //* Description: Av_timer0SwPWM is a function to generate a software PWM on a GPIO pin 
			//the freq, port, and the pin of the output in the timers.h 
 //* @param dutyCycle : the duty cycle of the PWM in percentage
 //* @param freq : the frequency of the PWM in Hz
 //*/
//void Av_timer0SwPWM(uint8 dutyCycle,uint64 freq)
//{
	//uint32 time_Total_ns = (1000000000 / freq);
	//uint32 time_On_ns  = ((dutyCycle/100.0) * time_Total_ns);
	//uint32 time_Off_ns = time_Total_ns - time_On_ns;
	//Av_gpioPinDirection(swPWM0_PORT,swPWM0_PIN,set_OUT);
	//while(1)
	//{
		//Av_gpioPinWrite(swPWM0_PORT,swPWM0_PIN,TRUE);
		//Av_timer0Delay_ns(time_On_ns);
		//Av_gpioPinWrite(swPWM0_PORT,swPWM0_PIN,FALSE);
		//Av_timer0Delay_ns(time_Off_ns);
	//}
//}


/*===========================Timer1 Control===============================*/
/**
 * Description:
 * @param controlA
 * @param controlB
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void Av_timer1Init(T1_MODE mode,T1_COM OC,T1_PRESCALER prescal, uint16 initialValue, uint8 outputCompareLow, uint8 outputCompareHigh,uint16 inputCapture, T1_INTERRUPT interruptMask)
{
	TCCR1A |= (mode & 0x03); 
	TCCR1A |= OC;
	TCCR1B |= (mode & 0x18);
	TCNT1L = initialValue;
	OCR1AL = outputCompareLow;
	OCR1AH = outputCompareHigh;
	TIMSK |= interruptMask;
	prescaller1 = prescal;
	switch(prescal)
	{
		case  T1_NO_CLOCK :
		preScaller_TIMER1= 0;
		break;
		case  T1_PRESCALER_1 :
		preScaller_TIMER1= 1;
		break;
		case  T1_PRESCALER_8 :
		preScaller_TIMER1= 8;
		break;
		case  T1_PRESCALER_64 :
		preScaller_TIMER1= 64;
		break;
		case  T1_PRESCALER_256 :
		preScaller_TIMER1= 256;
		break;
		case  T1_PRESCALER_1024 :
		preScaller_TIMER1= 1024;
		break;
	}
		
}
/**
 * Description: set the Reg TCNT1L to a value
 * @param value the value to be set with no more than 255
 */

void Av_timer1SetA(uint8 value)
{
	TCNT1L = value;
}
/**
 * Description: set the Reg TCNT1H to a value
 * @param value the value to be set with no more than 255
 */

void Av_timer1SetB(uint8 value)
{
	TCNT1H = value;
}
/**
 * Description: read the value of the TCNT1L Register
 * @return return the value
 */

uint8 Av_timer1ReadA(void)
{
	return ((uint8) TCNT1L);
}
/**
 * Description: read the value of the TCNT1H Register
 * @return return the value
 */
uint8 Av_timer1ReadB(void)
{
	return TCNT1H;
}
/**
 * Description: start the counting from the moment of this function call
  * @param value the value to be set in the prescaller pins in the TCCR2 Reg
 */
void Av_timer1Start(void)
{
	TCCR1B = (TCCR1B & 0xf8) | (prescaller1);
}
/**
* Description: Stop the Timer/Counter by setting the the prescaller pins to 0
*/
void Av_timer1Stop(void)
{
	TCCR1B &= 0xf8;
}
/**
 * Description: Delay function pooling based to block the code for a specific amount of time
 * @param delay the time I want to delay in ms
 */
void Av_timer1Delay_ms(uint16 delay)
{
	volatile sint64 counter = (((sint64)delay) * F_CPU) / (65535 * preScaller_TIMER1 * 1000.0);
	Av_timer1Start();
	while(counter-- > 0)
	{
		while( (TIFR & 0x04) == 0);
		TIFR |= 0x04;
	}
	Av_timer1Stop();
}



/**
 * Description: Delay function pooling based to block the code for a specific amount of time
 * @param delay the time I want to delay in ns
 */
void Av_timer1Delay_ns(uint32 delay)
{
	volatile sint64 counter = ((uint64) delay) * F_CPU / (256.0 * preScaller_TIMER1 * 1000000000.0);
	Av_timer1Start();
	while(counter-- > 0)
	{
		while( (TIFR & 0x04) == 0);
		TIFR |= 0x04;
	}
	Av_timer1Stop();
}

/**
 * Description: Av_timer1SwPWM is a function to generate a software PWM on a GPIO pin 
			the freq, port, and the pin of the output is configured in timers.h 
 * @param dutyCycle : the duty cycle of the PWM in percentage
 * @param freq : the frequency of the PWM in Hz
 */
void Av_timer1SwPWM(uint8 dutyCycle,uint64 freq)
{
	uint32 time_Total_ns = (1000000000 / freq);
	uint32 time_On_ns  = ((dutyCycle/100.0) * time_Total_ns);
	uint32 time_Off_ns = time_Total_ns - time_On_ns;
	Av_gpioPinDirection(swPWM1_PORT,swPWM1_PIN,set_OUT);

	while(1)
	{
		Av_gpioPinWrite(swPWM1_PORT,swPWM1_PIN,TRUE);
		Av_timer1Delay_ns(time_On_ns);
		Av_gpioPinWrite(swPWM1_PORT,swPWM1_PIN,FALSE);
		Av_timer1Delay_ns(time_Off_ns);
	}	
}

/**
 * Description: PWM_PhaseCorrect_Init is a function to initiate a PWM on a GPIO pin OC1 
			the freq, port, and the pin of the output are configured in the timers.h 
 * @param dutyCycle the duty cycle of the PWM in percentage
 * @param freq the frequency of the PWM in Hz
 */
void PWM_PhaseCorrect_Init(uint8 dutyCycle,uint8 freq)
{
	uint8 OCR_value;
	OCR_value = (uint8) (dutyCycle * 256 / 100);
	Av_gpioPinDirection(myPORTD,BIT5,set_OUT);
	//OCR1AL = 100;
	//TCCR1A = 0x83;
	//TCCR1B = 0x15;
	Av_timer1Init(T1_PWM_PhaseCorrect_ICR1_MODE,T1_OC1A_CLEAR,T1_PRESCALER_1,0,OCR_value,0,0,T1_POLLING);
	Av_timer1Start();
}


/*===========================Timer2 Control===============================*/
/**
 * Description: this function is to initialize the Timer2 
 * @mode  the mode of the timer
 * @param OC0 the output pin
 * @param prescal the prescaller of the timer
 * @param initialValue the initial value to be set in the TCNT0 Reg
 * @param outputCompare the value to be set in the OCR0 Reg 
 * @param interruptMask Enable or disable the interrupts of the Timer
 */
void Av_timer2Init(T2_MODE mode,T2_COM OC0,T2_PRESCALER prescal, uint8 initialValue, uint8 outputCompare, T2_INTERRUPT interruptMask)
{
	TCCR2 |= (mode|OC0);
	TCNT2 = initialValue;
	OCR2  = outputCompare;
	TIMSK |= interruptMask;
	prescaller2 = prescal;
		switch(prescal)
		{
			case T2_NO_CLOCK : 
			preScaller_TIMER2= 0;
			break;	
			case  T2_PRESCALER_1 :
			preScaller_TIMER2= 1;
			break;
			case  T2_PRESCALER_8 :
			preScaller_TIMER2= 8;
			break;
			case  T2_PRESCALER_32 :
			preScaller_TIMER2= 32;
			break;
			case  T2_PRESCALER_64 :
			preScaller_TIMER2= 64;
			break;
			case  T2_PRESCALER_128 :
			preScaller_TIMER2= 128;
			break;
			case  T2_PRESCALER_256 :
			preScaller_TIMER2= 256;
			break;
			case  T2_PRESCALER_1024 :
			preScaller_TIMER2= 1024;
			break;
		}
}


/**
 * Description: set the Reg TCNT2 to a value
 * @param value the value to be set with no more than 255
 */

void Av_timer2Set(uint8 value)
{
	TCNT2 = value;
}


/**
 * Description: read the value of the TCNT2 Register
 * @return return the value
 */

uint8 Av_timer2Read(void)
{
	return TCNT2;
}

/**
 * Description: start the counting from the moment of this function call
  * @param value the value to be set in the prescaller pins in the TCCR2 Reg
 */
void Av_timer2Start(void)
{
		TCCR2 |= prescaller2;
}

/**
 * Description: Stop the Timer/Counter by setting the the prescaller pins to 0
 */
void Av_timer2Stop(void)
{
	TCCR2 &= ~(0x07);
}

/**
 * Description: Delay function pooling based to block the code for a specific amount of time
 * @param delay the time I want to delay in ms
 */
void Av_timer2Delay_ms(uint16 delay)
{
	volatile sint64 counter = delay *(F_CPU / (256.0 * preScaller_TIMER2 * 1000.0));
	Av_timer2Start();
	while(counter-- > 0)
	{
		while( (TIFR & 0x40) == 0);
		TIFR |= 0x40;
	}
	Av_timer2Stop();
}


/**
 * Description: Delay function pooling based to block the code for a specific amount of time
 * @param delay the time I want to delay in ns
 */
void Av_timer2Delay_ns(uint32 delay)
{
	volatile sint64 counter = ((uint64) delay) * F_CPU / (256.0 * preScaller_TIMER2 * 1000000000.0);
	Av_timer2Start();
	while(counter-- > 0)
	{
		while( (TIFR & 0x40) == 0);
		TIFR |= 0x40;
	}
	Av_timer2Stop();
}

/**
 * Description: Av_timer2SwPWM is a function to generate a software PWM on a GPIO pin 
			the freq, port, and the pin of the output in the timers.h 
 * @param dutyCycle : the duty cycle of the PWM in percentage
 */
void Av_timer2SwPWM(uint8 dutyCycle,uint64 freq)
{
	uint32 time_Total_ns = (1000000000 / freq);
	uint32 time_On_ns  = ((dutyCycle/100.0) * time_Total_ns);
	uint32 time_Off_ns = time_Total_ns - time_On_ns;
	Av_gpioPinDirection(swPWM2_PORT,swPWM2_PIN,set_OUT);
	while(1)
	{
		Av_gpioPinWrite(swPWM2_PORT,swPWM2_PIN,TRUE);
		Av_timer2Delay_ns(time_On_ns);
		Av_gpioPinWrite(swPWM2_PORT,swPWM2_PIN,FALSE);
		Av_timer2Delay_ns(time_Off_ns);
	}
}



void AVE_timer1PWM(uint8 dutycycle , uint16 freq ){
	// in ms
	uint32 TOP_Value;
	uint32 Compare_Value;
	TOP_Value=(F_CPU/(2*freq*1024));
	Compare_Value=(TOP_Value*dutycycle)/100;
	ICR1H=(uint8)(TOP_Value>>8);
	ICR1L=(uint8)(TOP_Value);
	OCR1AH=(uint8)(Compare_Value>>8);
	OCR1AL=(uint8)(Compare_Value);
}