/***********************************************************************************************
*FILE NAME: DIO REG header File
*AUTHOR:yasmen gamal
*DESCRIPTION:DIO REG file to access registers by pointer to struct
***********************************************************************************************/

#ifndef DIO_REG_H_
#define DIO_REG_H_

#include "../lib/std_types.h"

typedef struct
{
uint8 Pin;
uint8 DDR;
uint8 Port;

}DIO_Regs;

/*PIN register its base address and by struct can access other register by moving
 * 8 bits size of (pin,DDR,port)
 * */
#define PORTA_BASE	(*(volatile  DIO_Regs *)0x39)
#define PORTB_BASE 	(*(volatile  DIO_Regs *)0x36)
#define PORTC_BASE	(*(volatile  DIO_Regs *)0x33)
#define PORTD_BASE 	(*(volatile  DIO_Regs *)0x30)





#endif /*DIO_REG_H_ */
