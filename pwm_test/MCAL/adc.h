/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: yasmen gamall
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "../lib/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*voltage Reference Selections for ADC*/
typedef enum{

	AREF,AVCC,reserved,internal_volatge

}ADC_ReferenceVolatge;

/*DC Prescaler Selections*/
typedef enum{

	NO_Prescaler,F_CPU2,F_CPU4,F_CPU8,F_CPU16,F_CPU32,F_CPU64,F_CPU128

}ADC_Prescaler;

typedef struct{

	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;

}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
