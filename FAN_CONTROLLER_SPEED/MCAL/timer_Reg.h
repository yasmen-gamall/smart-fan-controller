
#ifndef TIMER_REG_H_
#define TIMER_REG_H_
#include"../lib/std_types.h"

#define TCNT0_REG    (*(volatile uint8 *const)0x52)
#define TCCR0_REG    (*(volatile uint8 *const)0x53)
#define OCR0_REG      (*(volatile uint8 *const)0x5C)
#define TIFR_REG     (*(volatile uint8 *const)0x58)
#define TIMSK_REG    (*(volatile uint8 *const)0x59)
#define TCCR1A_REG   (*(volatile uint8 *const)0x4F)
#define TCCR1B_REG   (*(volatile uint8 *const)0x4E)
#define TCNT1L_REG   (*(volatile uint16 *const)0x4C) //uint16 to access tcnt1h
#define OCR1AL_REG   (*(volatile uint16 *const)0x4A)
#define OCR1BL_REG   (*(volatile uint16 *const)0x48)
#define ICR1L_REG    (*(volatile uint16 *const)0x46)
#define TCCR2_REG    (*(volatile uint16 *const)0x45)
#define TCNT2_REG    (*(volatile uint16 *const)0x44)
#define OCR2_REG     (*(volatile uint16 *const)0x43)


typedef enum
{
   CSS_0,CS_01,CS_02,WGM_01,COM_00,COM_01,WGM_00,FOC_0

}TCCR0_BITS;


typedef enum
{
	TOV_0,OCF_0,TOV_1,OCF_1B,OCF_1A,ICF_1,TOV_2,OCF_2
}TIFR_BITS;


typedef enum
{

 TOIE_0,OCIE_0,TOIE_1,OCIE_1B,OCIE_1A,TICIE_1,TOIE_2,OCIE_2
}TIMSK_BITS;



typedef enum
{
	WGM_10,WGM_11,FOC_1B,FOC_1A,COM_1B0,COM_1B1,COM_1A0,COM_1A1
}TCCR1A_BITS;


typedef enum
{
	CS_10,CS_11,CS_12,WGM_12,WGM_13,RESERVED_1,ICES_1,ICNC_1
}TCCR1B_BITS;

typedef enum
{
	CS_20,CS_21,CS_22,WGM_21,COM_20,COM_21,WGM_20,FOC_2
}TCCR2_BITS;




#endif /* TIMER_REG_H_ */
