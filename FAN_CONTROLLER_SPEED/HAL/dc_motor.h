/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dc_motor.c
 *
 * Description: Source file for dc motor
 *
 * Author: yasmen gamal
 *
 ***************************************************************************/
#include"../LIB/std_types.h"


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#define Motor_IN1_PORT_ID   PORTB_ID
#define Motor_IN1_PIN_ID    PIN0_ID

#define Motor_IN2_PORT_ID   PORTB_ID
#define Motor_IN2_PIN_ID    PIN1_ID

#define Motor_EN1_PORT_ID   PORTB_ID
#define Motor_EN1_PIN_ID    PIN3_ID

typedef enum{

	Stop,Clock_Wise,Anti_Clock_Wise

}DcMotor_State;
void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* DC_MOTOR_H_ */
