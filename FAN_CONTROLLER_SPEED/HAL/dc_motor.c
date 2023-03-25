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
 *********************************************************************/
#include"../MCAL/DIO_interface.h"
#include"../MCAL/PWM.h"
#include"dc_motor.h"

void DcMotor_Init(void) {
	DIO_vSetPinDirection( Motor_IN1_PORT_ID, Motor_IN1_PIN_ID, PIN_OUTPUT);
	DIO_vSetPinDirection( Motor_IN2_PORT_ID, Motor_IN2_PIN_ID, PIN_OUTPUT);

	DIO_vWritePin(Motor_IN1_PORT_ID, Motor_IN1_PIN_ID, LOGIC_LOW);
	DIO_vWritePin(Motor_IN2_PORT_ID, Motor_IN1_PIN_ID, LOGIC_LOW);

}

void DcMotor_Rotate(DcMotor_State state, uint8 speed) {
	switch (state) {
	case 0:
		DIO_vWritePin(Motor_IN1_PORT_ID, Motor_IN1_PIN_ID, LOGIC_LOW);
		DIO_vWritePin(Motor_IN2_PORT_ID, Motor_IN1_PIN_ID, LOGIC_LOW);
		break;

	case 1:
		DIO_vWritePin(Motor_IN1_PORT_ID, Motor_IN1_PIN_ID, LOGIC_LOW);
		DIO_vWritePin(Motor_IN2_PORT_ID, Motor_IN1_PIN_ID, LOGIC_HIGH);
		break;

	case 2:
		DIO_vWritePin(Motor_IN1_PORT_ID, Motor_IN1_PIN_ID, LOGIC_HIGH);
		DIO_vWritePin(Motor_IN2_PORT_ID, Motor_IN1_PIN_ID, LOGIC_LOW);
		break;
	}

	switch (speed) {
	case 0:
		PWM_Generate_CHANNELA(0, 500);
		break;
	case 25:

		//the speed of motor is 25% of the maximum speed
		PWM_Generate_CHANNELA(30, 5000);
		break;
	case 50:
		// the speed of motor 50% of the maximum speed
		PWM_Generate_CHANNELA(50, 10000);
		break;
	case 75:
		//the speed of motor 75% of the maximum speed
		PWM_Generate_CHANNELA(80, 20000);
		break;

	}
}

