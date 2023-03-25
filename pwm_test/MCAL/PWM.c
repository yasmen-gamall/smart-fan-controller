#include"PWM.h"
#include"timer_Reg.h"
#include"../lib/std_types.h"
#include"DIO_interface.h"
#include"../lib/common_macros.h"


#define    F_CPU           8000000ul

void PWM_Init() {
if(CONFIG.channel==channelA)
{

if(CONFIG.PWM_mode==NON_INVERTING)
	{
		TCCR1A_REG &= ~(1 << COM_1A0);
		TCCR1A_REG |= (1 << COM_1A1);

	}
else if(CONFIG.PWM_mode==INVERTING)
{

                	   TCCR1A_REG |=(1<<COM_1A0);
                	   TCCR1A_REG |=(1<<COM_1A1);


}
//#endif

if(CONFIG.mode==TIMER_FAST_PWM_MODE)
	{
		CLEAR_BIT(TCCR1A_REG, WGM_10);
		SET_BIT(TCCR1A_REG, WGM_11);
		SET_BIT(TCCR1B_REG, WGM_12);
		SET_BIT(TCCR1B_REG, WGM_13);

	}

else if(CONFIG.mode==TIMER_Phase_MODE)
{

						CLEAR_BIT(TCCR1A_REG,WGM_10);
						SET_BIT(TCCR1A_REG,WGM_11);
						CLEAR_BIT(TCCR1B_REG,WGM_12);
						SET_BIT(TCCR1B_REG,WGM_13);
}
//#endif
}
else if(CONFIG.channel==channelB)

#if(PWM_mode ==NON_INVERTING)
{
                	   TCCR1A_REG &=~(1<<COM_1B0);
                	   TCCR1A_REG |=(1<<COM_1B1);



}
#elif(PWM_mode==INVERTING)
{

                	   TCCR1A_REG |=(1<<COM_1B0);
                	   TCCR1A_REG |=(1<<COM_1B1);


}
#endif

#if(mode==TIMER_FAST_PWM_MODE)
{
	CLEAR_BIT(TCCR1A_REG,WGM_10);
	SET_BIT(TCCR1A_REG,WGM_11);
	SET_BIT(TCCR1B_REG,WGM_12);
	SET_BIT(TCCR1B_REG,WGM_13);

}

#elif(mode==TIMER_Phase_MODE)
{

						CLEAR_BIT(TCCR1A_REG,WGM_10);
						SET_BIT(TCCR1A_REG,WGM_11);
						CLEAR_BIT(TCCR1B_REG,WGM_12);
						SET_BIT(TCCR1B_REG,WGM_13);
}
#endif



//#endif

}
void PWM_Generate_CHANNELA(uint8 Copy_u8DutyCycle, uint32 Copy_u32freq) {

	if (CONFIG.mode == TIMER_FAST_PWM_MODE)

	{
		uint16 TOP;
		//TCNT1L_REG =CONFIG.initial_value;
		TCNT1L_REG=200;
		TOP=250;
		//TOP = (F_CPU / (CONFIG.prescaler * Copy_u32freq)) - 1; //from equation pwm in fast mode
		ICR1L_REG = TOP + 1;

		if (CONFIG.PWM_mode == NON_INVERTING)

		{
			OCR1AL_REG =((Copy_u8DutyCycle / 100) * (TOP + 1) - 1); //non inverting mince 1 due to tick from top to zero
			TCCR1B_REG = (TCCR1B_REG & 0xF8) | (CONFIG.prescaler);/*prescaler bits select (CS01,CS00,CS02)*/

		}
		else if (CONFIG.PWM_mode == INVERTING) {
			OCR1AL_REG = ((Copy_u8DutyCycle / 100) * (TOP + 1));
			TCCR1B_REG = (TCCR1B_REG & 0xF8) | (CONFIG.prescaler);/*prescaler bits select (CS01,CS00,CS02)*/

		}



	}

	else if (CONFIG.mode == TIMER_Phase_MODE)

	{
		uint16 TOP;
		TCNT1L_REG = CONFIG.initial_value;
		TOP = (F_CPU / (2 * CONFIG.prescaler * Copy_u32freq)); //from equation pwm in phase mode
		ICR1L_REG = TOP;

		if (CONFIG.PWM_mode == NON_INVERTING) {
			OCR1AL_REG = ((Copy_u8DutyCycle / 100) * (TOP)); //non inverting mince 1 due to tick from top to zero
			TCCR1B_REG = (TCCR1B_REG & 0xF8) | (CONFIG.prescaler);/*prescaler bits select (CS01,CS00,CS02)*/

		} else if (CONFIG.PWM_mode == INVERTING) {
			OCR1AL_REG = (TOP - (Copy_u8DutyCycle / 100) * (TOP));
			TCCR1B_REG = (TCCR1B_REG & 0xF8) | (CONFIG.prescaler);/*prescaler bits select (CS01,CS00,CS02)*/

		}

		//TCCR1B_REG = (TCCR1B_REG & 0xF8) | (CONFIG.prescaler);/*prescaler bits select (CS01,CS00,CS02)*/

	}
	DIO_vSetPinDirection(PORTD_ID,PIN5_ID,PIN_OUTPUT);

}

void PWM_Generate_CHANNELB(uint8 Copy_u8DutyCycle, uint32 Copy_u32freq) {

	uint16 TOP;
	TCNT1L_REG = CONFIG.initial_value;
	if (CONFIG.mode == TIMER_FAST_PWM_MODE) {

		TOP = (F_CPU / (CONFIG.prescaler * Copy_u32freq)) - 1; //from equation pwm in fast mode
		ICR1L_REG = TOP + 1;
		if (CONFIG.PWM_mode == NON_INVERTING) {
			OCR1BL_REG = ((Copy_u8DutyCycle / 100) * (TOP + 1) - 1); //non inverting mince 1 due to tick from top to zero
			TCCR1B_REG = (TCCR1B_REG & 0xF8) | (CONFIG.prescaler);/*prescaler bits select (CS01,CS00,CS02)*/
		} else if (CONFIG.PWM_mode == INVERTING) {
			OCR1BL_REG = ((Copy_u8DutyCycle / 100) * (TOP + 1));
			TCCR1B_REG = (TCCR1B_REG & 0xF8) | (CONFIG.prescaler);/*prescaler bits select (CS01,CS00,CS02)*/
		}

	}

	else if (CONFIG.mode == TIMER_Phase_MODE) {
		uint16 TOP;
		TCNT1L_REG = CONFIG.initial_value;

		TOP = (F_CPU / (2 * CONFIG.prescaler * Copy_u32freq)); //from equation pwm in phase mode
		ICR1L_REG = TOP;
		if (CONFIG.PWM_mode == NON_INVERTING) {
			OCR1BL_REG = ((Copy_u8DutyCycle / 100) * (TOP)); //non inverting mince 1 due to tick from top to zero
			TCCR1B_REG = (TCCR1B_REG & 0xF8) | (CONFIG.prescaler);/*prescaler bits select (CS01,CS00,CS02)*/
		} else if (CONFIG.PWM_mode == INVERTING) {
			OCR1BL_REG = (TOP - (Copy_u8DutyCycle / 100) * (TOP));
			TCCR1B_REG = (TCCR1B_REG & 0xF8) | (CONFIG.prescaler);/*prescaler bits select (CS01,CS00,CS02)*/
		}

	}

}

