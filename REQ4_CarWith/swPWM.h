/*
 * swPWM.h
 *
 * Created: 10/23/2019 8:10:14 PM
 *  Author: Ammar Shahin
 */ 


#ifndef SWPWM_H_
#define SWPWM_H_

#define timer_Number TIMER_0

/**
 * Description:
 * @param delay
 */
void Av_SwPWM(uint8 dutyCycle, uint32 freq,uint8 output_PORT,uint8 output_PIN);

#endif /* SWPWM_H_ */