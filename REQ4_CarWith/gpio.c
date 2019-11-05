/*
 * gpio.c
 *
 * Created: 10/21/2019 3:00:07 PM
 *  Author: Ammar Shahin
 */ 

#include "gpio.h"


/************************************************************************/
/*				 GPIO functions' Definitions                            */
/************************************************************************/

/*===========================PORT Control===============================*/
/**
 * Description: Used to set the Direction of the PORT
 * @param port : the port Name [myPORTA,myPORTB,myPORTC, or myPORTD]
 * @param direction : the Direction
 */
void Av_gpioPortDirection(uint8 port, uint8 direction)
{
	switch(port)
	{
		case myPORTA : 
						DDR_A = direction;
						break;
		case myPORTB :
						DDR_B = direction;
						break;
		case myPORTC :
						DDR_C = direction;
						break;
		case myPORTD :
						DDR_D = direction;
						break;	
	}
}

/**
 * Description: Write A value to the Port that has been selected as an output
 * @param port : the Port that I want to write to
 * @param value : the value to set (0 >> 128)
 */
void Av_gpioPortWrite(uint8 port, uint8 value)
{
	switch(port)
	{
		case myPORTA :
			PORT_A = value;
			break;
		case myPORTB :
			PORT_B = value;
			break;
		case myPORTC :
			PORT_C = value;
			break;
		case myPORTD :
			PORT_D = value;
			break;
	}
}
/**
 * Description: toggle the value of the port
 * @param port : the port
 */
void Av_gpioPortToggle(uint8 port)
{
	switch(port)
	{
		case myPORTA :
		PORT_A ^= 0xff;
		break;
		case myPORTB :
		PORT_B ^= 0xff;
		break;
		case myPORTC :
		PORT_C ^= 0xff;
		break;
		case myPORTD :
		PORT_D ^= 0xff;
		break;
	}
}

/**
 * Description: Read the value of the port (PIN Reg)
 * @param port : the Port that I want to Read from (PIN Reg only)
 * @return the value of the Reg
 */
uint8 Av_gpioPortRead(uint8 port)
{
	uint8 result = 0;
	switch(port)
	{
		case myPORTA :
		result =  PIN_A;
		break;
		case myPORTB :
		result = PIN_B;
		break;
		case myPORTC :
		result = PIN_C;
		break;
		case myPORTD :
		result = PIN_D;
		break;
	}
	return result;
}

/*===========================PIN Control===============================*/
/**
 * Description:
 * @param port
 * @param pins
 * @param direction
 */
void Av_gpioPinDirection(uint8 port, uint8 pins, uint8 direction)
{
	switch(port)
	{
		case myPORTA :
		{
		switch(direction)
		{
		case set_IN : 
		DDR_A &= ~(pins);
		break;
		case set_OUT : 
		DDR_A |= (pins);
		break;
		}
		}
		break;
		
		case myPORTB :
		{
		switch(direction)
		{
		case set_IN :
			DDR_B &= ~(pins);
			break;
		case set_OUT :
			DDR_B |= (pins);
			break;
		}
		}
		break;
		case myPORTC :
		{
			switch(direction)
			{
				case set_IN :
				DDR_C &= ~(pins);
				break;
				case set_OUT :
				DDR_C |= (pins);
				break;
			}
		}
		break;
		case myPORTD :
		{
			switch(direction)
			{
				case set_IN :
				DDR_D &= ~(pins);
				break;
				case set_OUT :
				DDR_D |= (pins);
				break;
			}
		}
		break;
	}
}

/**
 * Description:
 * @param port
 * @param pins
 * @param value
 */
void Av_gpioPinWrite(uint8 port, uint8 pins, uint8 value)
{
	switch(value)
	{
		case HIGH:
			switch(port)
			{
					case myPORTA :
						PORT_A |= (pins);
						break;
					case myPORTB :
						PORT_B |= (pins);
						break;
					case myPORTC :
						PORT_C |= (pins);
						break;
					case myPORTD :
						PORT_D |= (pins);
						break;
		}
		break;
		
		case LOW : 
		switch(port)
		{
			case myPORTA :
			PORT_A &= ~(pins);
			break;
			case myPORTB :
			PORT_B &= ~(pins);
			break;
			case myPORTC :
			PORT_C &= ~(pins);
			break;
			case myPORTD :
			PORT_D &= ~(pins);
			break;
		}
		break;	
	}
}
/**
 * Description:
 * @param port
 * @param pins
 */
void Av_gpioPinToggle(uint8 port, uint8 pins)
{
	switch(port)
	{
		case myPORTA :
		PORT_A ^= (pins);
		break;
		case myPORTB :
		PORT_B ^= (pins);
		break;
		case myPORTC :
		PORT_C ^= (pins);
		break;
		case myPORTD :
		PORT_D ^= (pins);
		break;
	}
}
/**
 * Description:
 * @param port
 * @param pin
 * @return
 */
uint8 Av_gpioPinRead(uint8 port, uint8 pin)
{
	uint8 result = 0;
	switch(port)
	{
		case myPORTA :
		result = ((PIN_A >> pin) & 0x01);
		break;
		case myPORTB :
		result = ((PIN_B >> pin) & 0x01);
		break;
		case myPORTC :
		result = ((PIN_C >> pin) & 0x01);
		break;
		case myPORTD :
		result = ((PIN_D >> pin) & 0x01);
		break;
	}
	return result;
}
/*===========================Upper Nibble Control===============================*/
/**
 * Description:
 * @param port
 * @param direction
 */
void Av_gpioUpperNibbleDirection(uint8 port, uint8 direction)
{
	switch(port)
	{
		case myPORTA :
		{
			switch(direction)
			{
				case set_IN :
				DDR_A &= 0x0f;
				break;
				case set_OUT :
				DDR_A |= 0xf0;
				break;
			}
		}
		break;
		case myPORTB :
		{
			switch(direction)
			{
				case set_IN :
				DDR_B &= 0x0f;
				break;
				case set_OUT :
				DDR_B |= 0xf0;
				break;
			}
		}
		break;
		case myPORTC :
		{
			switch(direction)
			{
				case set_IN :
				DDR_C &= 0x0f;
				break;
				case set_OUT :
				DDR_C |= 0xf0;
				break;
			}
		}
		break;
		case myPORTD :
		{
			switch(direction)
			{
				case set_IN :
				DDR_D &= 0x0f;
				break;
				case set_OUT :
				DDR_D |= 0xf0;
				break;
			}
		}
		break;
	}
}
/**
 * Description:
 * @param port
 * @param value
 */
void Av_gpioUpperNibbleWrite(uint8 port, uint8 value)
{
	switch(port)
	{
		case myPORTA :
		PORT_A = ((PORT_A & 0x0f) | (value << 4));
		break;
		case myPORTB :
		PORT_B = ((PORT_B & 0x0f) | (value << 4));
		break;
		case myPORTC :
		PORT_C = ((PORT_C & 0x0f) | (value << 4));
		break;
		case myPORTD :
		PORT_D = ((PORT_D & 0x0f) | (value << 4));
		break;
	}
}
/**
 * Description:
 * @param port
 */
void Av_gpioUpperNibbleToggle(uint8 port)
{
	switch(port)
	{
		case myPORTA :
		PORT_A ^= 0xf0;
		break;
		case myPORTB :
		PORT_B ^= 0xf0;
		break;
		case myPORTC :
		PORT_C ^= 0xf0;
		break;
		case myPORTD :
		PORT_D ^= 0xf0;
		break;
	}
}

/**
 * Description:
 * @param port
 * @return
 */
uint8 Av_gpioUpperNibbleRead(uint8 port)
{
	uint8 result = 0;
	switch(port)
	{
		case myPORTA :
		result = (PIN_A >> 4);
		break;
		case myPORTB :
		result = (PIN_B >> 4);
		break;
		case myPORTC :
		result = (PIN_C >> 4);
		break;
		case myPORTD :
		result = (PIN_D >> 4);
		break;
	}
	return result;
}

/*===========================Lower Nibble Control===============================*/
/**
 * Description:
 * @param port
 * @param direction
 */
void Av_gpioLowerNibbleDirection(uint8 port, uint8 direction)
{
	switch(port)
	{
		case myPORTA :
		{
			switch(direction)
			{
				case set_IN :
				DDR_A &= 0xf0;
				break;
				case set_OUT :
				DDR_A |= 0x0f;
				break;
			}
		}
		break;
		case myPORTB :
		{
			switch(direction)
			{
				case set_IN :
				DDR_B &= 0xf0;
				break;
				case set_OUT :
				DDR_B |= 0x0f;
				break;
			}
		}
		break;
		case myPORTC :
		{
			switch(direction)
			{
				case set_IN :
				DDR_C &= 0xf0;
				break;
				case set_OUT :
				DDR_C |= 0x0f;
				break;
			}
		}
		break;
		case myPORTD :
		{
			switch(direction)
			{
				case set_IN :
				DDR_D &= 0xf0;
				break;
				case set_OUT :
				DDR_D |= 0x0f;
				break;
			}
		}
		break;
	}
}

/**
 * Description:
 * @param port
 * @param value
 */
void Av_gpioLowerNibbleWrite(uint8 port, uint8 value)
{
	switch(port)
	{
		case myPORTA :
		PORT_A = (PORT_A & 0xf0) | (value & 0x0f);
		break;
		case myPORTB :
		PORT_B = (PORT_B & 0xf0) | (value & 0x0f);
		break;
		case myPORTC :
		PORT_C = (PORT_C & 0xf0) | (value & 0x0f);
		break;
		case myPORTD :
		PORT_D = (PORT_D & 0xf0) | (value & 0x0f);
		break;
	}
}

/**
 * Description:
 * @param port
 */
void Av_gpioLowerNibbleToggle(uint8 port)
{
	switch(port)
	{
		case myPORTA :
		PORT_A ^= 0x0f;
		break;
		case myPORTB :
		PORT_B ^= 0x0f;
		break;
		case myPORTC :
		PORT_C ^= 0x0f;
		break;
		case myPORTD :
		PORT_D ^= 0x0f;
		break;
	}
}
/**
 * Description:
 * @param port
 * @return
 */
uint8 Av_gpioLowerNibbleRead(uint8 port)
{
	uint8 result = 0;
	switch(port)
	{
		case myPORTA :
		result = (PIN_A & 0x0f);
		break;
		case myPORTB :
		result = (PIN_B & 0x0f);
		break;
		case myPORTC :
		result = (PIN_C & 0x0f);
		break;
		case myPORTD :
		result = (PIN_D & 0x0f);
		break;
	}
	return result;
}
