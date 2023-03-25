/***********************************************************************************************
 *FILE NAME: DIO interface header File
 *AUTHOR:yasmen gamal
 *DESCRIPTION:DIO functions prototypes
 ***********************************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../lib/std_types.h"




#define NUM_OF_PINS_PER_PORT 8
#define NUM_OF_PORTS 4


#define PORTA_ID               0
#define PORTB_ID               1
#define PORTC_ID               2
#define PORTD_ID               3

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7
/*******************************************************************************
 *                             GPIO  Types Declaration                             *
 *******************************************************************************/
typedef enum
{
	PIN_INPUT,PIN_OUTPUT
}GPIO_PinDirectionType;

typedef enum
{
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_PortDirectionType;


void DIO_vSetPinDirection(uint8 Copy_u8PORT,uint8 Copy_u8PinNumber,uint8 copy_u8state);
void DIO_vWritePin(uint8 Copy_u8PORT,uint8 Copy_u8PinNumber,uint8 Copy_u8value);
void DIO_vTogglePin(uint8 Copy_u8PORT,uint8 Copy_u8PinNumber);
void DIO_vSetPortDirection(uint8 Copy_u8PORT,uint8 copy_u8state);
void DIO_vWritePort(uint8 Copy_u8PORT,uint8 Copy_u8value);
uint8 DIO_u8GetPinValue(uint8 Copy_u8PORT,uint8 Copy_u8PinNumber);
void DIO_vTogglrPort(uint8 Copy_u8PORT);
uint8 DIO_GETPortValue(uint8 Copy_u8PORT);


#endif /* DIO_INTERFACE_H_ */
