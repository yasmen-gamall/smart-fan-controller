/*
 * main.c
 *
 *  Created on: Mar 3, 2023
 *      Author: PC
 */

#include"MCAL/adc.h"
#include"MCAL/PWM.h"
#include"HAL/dc_motor.h"
#include"HAL/LCD.h"
#include"HAL/lm35_sensor.h"
#include"MCAL/DIO_interface.h"

int main() {
	uint8 temperature = 0;

	ADC_ConfigType type;
	type.prescaler = F_CPU8;
	type.ref_volt = internal_volatge;

	ADC_init(&type);
	LCD_init();
	DcMotor_Init();
	PWM_Init();


	while (1) {

		temperature = LM35_getTemperature();
		LCD_displayStringRowColumn(1, 4, "temp =    C");

		//If the temperature is less than 30C turn off fan

		if (temperature < 25) {

			LCD_displayStringRowColumn(0, 4, "Fan is OFF");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(Stop, 0);

		}

		/*If the temperature is greater than or equal 30C or less than 30 turn on the fan with 20% of its
		 maximum speed*/
		else if ((temperature >= 25) && (temperature < 30)) {

			LCD_displayStringRowColumn(0, 4, "Fan is ON  ");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(Clock_Wise, 20);
		}

		/*If the temperature is greater than or equal 30C or less than 35 turn on the fan with 50% of its
		 maximum speed*/
	else if ((temperature >= 30) && (temperature < 35)) {

			LCD_displayStringRowColumn(0, 4, "Fan is ON");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(Clock_Wise, 50);
		}

		/*If the temperature is greater than or equal 35C o turn on the fan with 80% of its
		 maximum speed*/
	else if (temperature >= 35) {

			LCD_displayStringRowColumn(0, 4, "Fan is ON");
			LCD_moveCursor(1, 11);
			LCD_intgerToString(temperature);
			DcMotor_Rotate(Clock_Wise, 80);
		}

	}
}
