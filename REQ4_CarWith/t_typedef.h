/*
 * t_typedef.h
 *
 * Created: 10/21/2019 3:33:11 PM
 *  Author: Ammar Shahin
 */ 


#ifndef T_TYPEDEF_H_
#define T_TYPEDEF_H_

/************************************************************************/
/*                   typedefs for standard types                        */
/************************************************************************/
typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed int sint16;
typedef signed long int sint32;
typedef signed long long sint64;
typedef volatile uint8* const reg_type;


/************************************************************************/
/*				 Enum for defining bit numbers                          */
/************************************************************************/
typedef enum EN_bits
{
	BIT0 = 0x01,	// defines BIT0 in a register
	BIT1 = 0x02,	// defines BIT1 in a register
	BIT2 = 0x04,	// defines BIT2 in a register
	BIT3 = 0x08,	// defines BIT3 in a register
	BIT4 = 0x10,	// defines BIT4 in a register
	BIT5 = 0x20,	// defines BIT5 in a register
	BIT6 = 0x40,	// defines BIT6 in a register
	BIT7 = 0x80,	// defines BIT7 in a register
}EN_bits;

/************************************************************************/
/*				 		defining boolean values                         */
/************************************************************************/
#define FALSE 	0	// defines boolean false
#define TRUE 	1	// defines boolean true


/************************************************************************/
/*						 LOW/HIGH defines                               */
/************************************************************************/
#define LOW  0	// defines LOW value for a bit
#define HIGH 1	// defines HIGH value for a bit

/************************************************************************/
/*                       ENUM to set the Direction                      */
/************************************************************************/

typedef enum{
	set_IN = 0x00,
	set_OUT = 0xff,
	}En_Dir;


#define NO_CHANGE -1
#endif /* T_TYPEDEF_H_ */