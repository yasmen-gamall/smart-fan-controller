
#ifndef PWM_H_
#define PWM_H_

#include"../lib/std_types.h"


typedef enum
{
	TIMER_NORMAL_MODE,TIMER_Phase_MODE,TIMER_COMPARE_MODE,TIMER_FAST_PWM_MODE
}TIMER_MODES;
typedef enum
{
NOCLOCK_STOPPED,NOPRESCALER,PRESCALER_8,PRESCALER_64,PRESCALER_256,PRESCALER_1024,EXTERNAL_FALLING,EXTERNAL_RIASING
}PWM_prescaler;


typedef enum
{

	NORMAL,TOGGLE_OC1A,NON_INVERTING,INVERTING
}PWM_MODE;

typedef enum
{
   channelA,channelB
}Timer_1_Channels;


typedef struct
{
	Timer_1_Channels channel;
	PWM_prescaler prescaler;
	TIMER_MODES  mode;
	PWM_MODE PWM_mode ;
	uint8 initial_value;
	uint8 compare_value;

}PWM_CONFIG;


static PWM_CONFIG CONFIG={channelA,PRESCALER_64,TIMER_FAST_PWM_MODE,NON_INVERTING,200};

void PWM_Init();
void PWM_Generate_CHANNELA(uint8 Copy_u8DutyCycle,uint32 Copy_u32freq);
void PWM_Generate_CHANNELB(uint8 Copy_u8DutyCycle,uint32 Copy_u32freq);




#endif /* PWM_H_ */
