/*
 * timers.h
 *
 * Created: 10/22/2019 2:04:16 PM
 *  Author: AVE-LAP-44
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include "t_typedef.h"
#include "timer_LCFG.h"


/************************************************************************/
/*                     Timers' Registers                                  */
/************************************************************************/
#define TIMSK  *((reg_type)0x59)
#define TIFR   *((reg_type)0x58)
#define TWCR   *((reg_type)0x56)
#define TCCR0  *((reg_type)0x53)
#define TCNT0  *((reg_type)0x52)
#define TCCR1A *((reg_type)0x4f)
#define TCCR1B *((reg_type)0x4e)
#define TCNT1H *((reg_type)0x4d)
#define TCNT1L *((volatile uint16* const)0x4c)
#define OCR1AH *((reg_type)0x4b)
#define OCR1AL *((reg_type)0x4a)
#define OCR1BH *((reg_type)0x49)
#define OCR1BL *((reg_type)0x48)
#define ICR1H  *((reg_type)0x47)
#define ICR1L  *((reg_type)0x46)
#define TCCR2  *((reg_type)0x45)
#define TCNT2  *((reg_type)0x44)
#define OCR2   *((reg_type)0x43)
#define OCR0   *((reg_type)0x5C)


/************************************************************************/
/*                   defined modes and preScaller_TIMER0s               */
/************************************************************************/

#define swPWM0_FREQ 40000UL 
#define swPWM0_PORT myPORTA
#define swPWM0_PIN  BIT0

#define swPWM1_FREQ 100UL
#define swPWM1_PORT myPORTB
#define swPWM1_PIN  BIT6

#define swPWM2_FREQ 1UL
#define swPWM2_PORT myPORTB
#define swPWM2_PIN  BIT4



// for timer 0
typedef enum {
	T0_NORMAL_MODE=0x00,
	T0_PWM_MODE=0x40,
	T0_COMP_MODE=0x08,
	T0_FastPWM_MODE=0x48
}T0_MODE;

typedef enum {
	T0_OC0_DIS=0x00,
	T0_OC0_TOGGLE=0x10,
	T0_OC0_CLEAR=0x20,
	T0_OC0_SET=0x30,
}T0_COM;

typedef enum {
	T0_NO_CLOCK=0,
	T0_PRESCALER_1=0x01,
	T0_PRESCALER_8=0x02,
	T0_PRESCALER_64=0x03,
	T0_PRESCALER_256=0x04,
	T0_PRESCALER_1024=0x05,
}T0_PRESCALER;

typedef enum {
	T0_POLLING=0x00,
	T0_INTERRUPT_NORMAL=0x01,
	T0_INTERRUPT_CMP=0x02
}T0_INTERRUPT;



// for timer 1
typedef enum {
	T1_NORMAL_MODE=0x00							,
	T1_PWM8Bit_MODE=0x01					    ,
	T1_PWM9Bit_MODE=0x02						,
	T1_PWM10Bit_MODE=0x03					    ,
	T1_COMPA_OCR1A_MODE=0x08					,
	T1_FastPWM8Bit_MODE=0x09					,
	T1_FastPWM9Bit_MODE=0x0A					,
	T1_FastPWM10Bit_MODE=0x0B					,
	T1_PWM_PhaseAndFreqCorrect_ICR1_MODE=0x10   ,
	T1_PWM_PhaseCorrect_ICR1_MODE=0x12          ,
	T1_PWM_PhaseCorrect_OCR1A_MODE=0x13         ,
	T1_COMPA_ICR1_MODE=0x18                     ,
	T1_FastPWM_ICR1_MODE=0x1A                   ,
	T1_FastPWM_OCR1A_MODE=0x1B                  ,
}T1_MODE;

typedef enum {
	T1_OC1A_DIS=0x00,
	T1_OC1A_TOGGLE=0x40,
	T1_OC1A_CLEAR=0x80,
	T1_OC1A_SET=0xC0,
	T1_OC1B_DIS=0x00,
	T1_OC1B_TOGGLE=0x10,
	T1_OC1B_CLEAR=0x20,
	T1_OC1B_SET=0x30,
}T1_COM;

typedef enum {
	T1_NO_CLOCK=0x00,
	T1_PRESCALER_1=0x01,
	T1_PRESCALER_8=0x02,
	T1_PRESCALER_64=0x03,
	T1_PRESCALER_256=0x04,
	T1_PRESCALER_1024=0x05,
}T1_PRESCALER;

typedef enum {
	T1_POLLING=0x00,
	T1_INTERRUPT_NORMAL = 0x04,
	T1_INTERRUPT_CMPA = 0x10,
	T1_INTERRUPT_CMPB = 0x08,
	T1_INTERRUPT_INCAP = 0x20,
}T1_INTERRUPT;





// for timer 2
typedef enum {
	T2_NORMAL_MODE=0x00,T2_PWM_MODE=0x40,T2_COMP_MODE=0x08,T2_FastPWM_MODE=0x48
}T2_MODE;

typedef enum {
	T2_OC0_DIS=0,
	T2_OC0_TOGGLE=0x10,
	T2_OC0_CLEAR=0x20,
	T2_OC0_SET=0x30
}T2_COM;

typedef enum {
	T2_NO_CLOCK=0x00,
	T2_PRESCALER_1=0x01,
	T2_PRESCALER_8=0x02,
	T2_PRESCALER_32=0x03,
	T2_PRESCALER_64=0x04,
	T2_PRESCALER_128=0x05,
	T2_PRESCALER_256=0x06,
	T2_PRESCALER_1024=0x07
}T2_PRESCALER;

typedef enum {
	T2_POLLING = 0x00,
	T2_INTERRUPT_NORMAL = 0x40,
	T2_INTERRUPT_CMP = 0x80
}T2_INTERRUPT;


/************************************************************************/
/*                   Timers' Functions' prototypes                      */
/************************************************************************/


/************************************************************************/
/*                   Timers' Functions' prototypes                      */
/************************************************************************/
uint8  Timer_Init(Timer_CFG_S* cfg_s);
uint8  Timer_Start(uint8 ch_no);
uint8  Timer_Stop(uint8 ch_no);
uint8  Timer_set_counter(uint8 ch_no,uint16 count);
uint8  Timer_getStatus(uint8 ch_no);
uint32 Timer_Read(uint8 ch_no);


///*===========================Timer0 Control===============================*/
//void Av_timer0Init(T0_MODE mode,T0_COM OC0,T0_PRESCALER prescal, uint8 initialValue, uint8 outputCompare, T0_INTERRUPT interruptMask);
//void Av_timer0Set(uint8 value);
//uint8 Av_timer0Read(void);
//void Av_timer0Start(void);
//void Av_timer0Stop(void);
//void Av_timer0Delay_ms(uint16 delay);
//void Av_timer0Delay_ns(uint32 delay);
//void Av_timer0SwPWM(uint8 dutyCycle,uint64 freq);

/*===========================Timer1 Control===============================*/
void Av_timer1Init(T1_MODE mode,T1_COM OC,T1_PRESCALER prescal, uint16 initialValue, uint8 outputCompareLow, uint8 outputCompareHigh,uint16 inputCapture, T1_INTERRUPT interruptMask);
void Av_timer1SetA(uint8 value);
void Av_timer1SetB(uint8 value);
uint8 Av_timer1ReadA(void);
uint8 Av_timer1ReadB(void);
void Av_timer1Start(void);
void Av_timer1Stop(void);
void Av_timer1Delay_ms(uint16 delay);
void Av_timer1Delay_ns(uint32 delay);
void Av_timer1SwPWM(uint8 dutyCycle,uint64 freq);
void fastPWM_Init(uint8 dutyCycle,uint8 freq);
void PWM_PhaseCorrect_Init(uint8 dutyCycle,uint8 freq);

/*===========================Timer2 Control===============================*/
void Av_timer2Init(T2_MODE mode,T2_COM OC0,T2_PRESCALER prescal, uint8 initialValue, uint8 outputCompare, T2_INTERRUPT interruptMask);
void Av_timer2Set(uint8 value);
uint8 Av_timer2Read(void);
void Av_timer2Start(void);
void Av_timer2Stop(void);
void Av_timer2Delay_ms(uint16 delay);
void Av_timer2Delay_ns(uint32 delay);
void Av_timer2SwPWM(uint8 dutyCycle,uint64 freq);

void AVE_timer1PWM(uint8 dutycycle , uint16 freq );

#endif /* TIMERS_H_ */