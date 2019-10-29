/*
 * gpio.h
 *
 * Created: 10/21/2019 3:00:30 PM
 *  Author: Ammar Shahin
 */ 


#ifndef T_GPIO_H_
#define T_GPIO_H_

#include "t_typedef.h"
#include "registers_ATmega32.h"

/************************************************************************/
/*				 		defining the PORTS Numbers                      */
/************************************************************************/
#define myPORTA  0
#define myPORTB  1
#define myPORTC  2
#define myPORTD  3


/************************************************************************/
/*				 Enum for defining PIN numbers                          */
/************************************************************************/
typedef enum EN_PINS
{
	PIN0 = 0,	// defines BIT0 in a register
	PIN1 = 1,	// defines BIT1 in a register
	PIN2 = 2,	// defines BIT2 in a register
	PIN3 = 3,	// defines BIT3 in a register
	PIN4 = 4,	// defines BIT4 in a register
	PIN5 = 5,	// defines BIT5 in a register
	PIN6 = 6,	// defines BIT6 in a register
	PIN7 = 7,	// defines BIT7 in a register
}EN_PINS;

/************************************************************************/
/*				 GPIO functions' prototypes	                            */
/************************************************************************/

/*===========================PORT Control===============================*/
/**
 * Description:
 * @param port
 * @param direction
 */
void Av_gpioPortDirection(uint8 port, uint8 direction);

/**
 * Description:
 * @param port
 * @param value
 */
void Av_gpioPortWrite(uint8 port, uint8 value);

/**
 * Description:
 * @param port
 */
void Av_gpioPortToggle(uint8 port);

/**
 * Description:
 * @param port
 * @return
 */
uint8 Av_gpioPortRead(uint8 port);

/*===========================PIN Control===============================*/
/**
 * Description:
 * @param port
 * @param pins
 * @param direction
 */
void Av_gpioPinDirection(uint8 port, uint8 pins, uint8 direction);

/**
 * Description:
 * @param port
 * @param pins
 * @param value
 */
void Av_gpioPinWrite(uint8 port, uint8 pins, uint8 value);

/**
 * Description:
 * @param port
 * @param pins
 */
void Av_gpioPinToggle(uint8 port, uint8 pins);

/**
 * Description:
 * @param port
 * @param pin
 * @return
 */
uint8 Av_gpioPinRead(uint8 port, uint8 pin);

/*===========================Upper Nibble Control===============================*/
/**
 * Description:
 * @param port
 * @param direction
 */
void Av_gpioUpperNibbleDirection(uint8 port, uint8 direction);

/**
 * Description:
 * @param port
 * @param value
 */
void Av_gpioUpperNibbleWrite(uint8 port, uint8 value);

/**
 * Description:
 * @param port
 */
void Av_gpioUpperNibbleToggle(uint8 port);

/**
 * Description:
 * @param port
 * @return
 */
uint8 Av_gpioUpperNibbleRead(uint8 port);

/*===========================Lower Nibble Control===============================*/
/**
 * Description:
 * @param port
 * @param direction
 */
void Av_gpioLowerNibbleDirection(uint8 port, uint8 direction);

/**
 * Description:
 * @param port
 * @param value
 */
void Av_gpioLowerNibbleWrite(uint8 port, uint8 value);

/**
 * Description:
 * @param port
 */
void Av_gpioLowerNibbleToggle(uint8 port);

/**
 * Description:
 * @param port
 * @return
 */
uint8 Av_gpioLowerNibbleRead(uint8 port);


#endif /* T_GPIO_H_ */