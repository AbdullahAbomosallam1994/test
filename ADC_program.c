/*
 * ADC_program.c
 *
 *  Created on: Feb 27, 2023
 *      Author: Abdullah.Abomosallam
 */

#include"../../LIB/BIT_MATH.h"
#include"../../LIB/STD_TYPES.h"
#include"ADC_interface.h"
#include"ADC_pcfg.h"
#include"ADC_private.h"

void ADC_voidInit()
{

#if ADC_VREF == ADC_AREF
	WRITE_BIT(ADMUX,6,0);
	WRITE_BIT(ADMUX,7,0);
#elif ADC_VREF == ADC_AVCC
	WRITE_BIT(ADMUX,6,1);
		WRITE_BIT(ADMUX,7,0);
#elif ADC_VREF == ADC_INTERNAL_2
	WRITE_BIT(ADMUX,6,1);
		WRITE_BIT(ADMUX,7,1);
#endif


#if ADC_ADJUSTMENT ==ADC_RIGHT

		WRITE_BIT(ADMUX,5,0);

#elif ADC_ADJUSTMENT ==ADC_LEFT

		WRITE_BIT(ADMUX,5,1);
#endif




#if ADC_CHANNEL_MODE ==ADC_SINGLE_ENDED

#if ADC_CHANNEL_SELECTION ==ADC_CHANNEL0
		WRITE_BIT(ADMUX,0,0);
		WRITE_BIT(ADMUX,1,0);
		WRITE_BIT(ADMUX,2,0);
		WRITE_BIT(ADMUX,3,0);
		WRITE_BIT(ADMUX,4,0);

#elif ADC_CHANNEL_SELECTION ==ADC_CHANNEL1
		WRITE_BIT(ADMUX,0,1);
		WRITE_BIT(ADMUX,1,0);
		WRITE_BIT(ADMUX,2,0);
		WRITE_BIT(ADMUX,3,0);
		WRITE_BIT(ADMUX,4,0);

#elif ADC_CHANNEL_SELECTION ==ADC_CHANNEL2
		WRITE_BIT(ADMUX,0,0);
		WRITE_BIT(ADMUX,1,1);
		WRITE_BIT(ADMUX,2,0);
		WRITE_BIT(ADMUX,3,0);
		WRITE_BIT(ADMUX,4,0);
#elif ADC_CHANNEL_SELECTION ==ADC_CHANNEL3
		WRITE_BIT(ADMUX,0,1);
		WRITE_BIT(ADMUX,1,1);
		WRITE_BIT(ADMUX,2,0);
		WRITE_BIT(ADMUX,3,0);
		WRITE_BIT(ADMUX,4,0);
#elif ADC_CHANNEL_SELECTION ==ADC_CHANNEL4
		WRITE_BIT(ADMUX,0,0);
		WRITE_BIT(ADMUX,1,0);
		WRITE_BIT(ADMUX,2,1);
		WRITE_BIT(ADMUX,3,0);
		WRITE_BIT(ADMUX,4,0);
#elif ADC_CHANNEL_SELECTION ==ADC_CHANNEL5
		WRITE_BIT(ADMUX,0,1);
		WRITE_BIT(ADMUX,1,0);
		WRITE_BIT(ADMUX,2,1);
		WRITE_BIT(ADMUX,3,0);
		WRITE_BIT(ADMUX,4,0);
#elif ADC_CHANNEL_SELECTION ==ADC_CHANNEL6
		WRITE_BIT(ADMUX,0,0);
		WRITE_BIT(ADMUX,1,1);
		WRITE_BIT(ADMUX,2,1);
		WRITE_BIT(ADMUX,3,0);
		WRITE_BIT(ADMUX,4,0);
#elif ADC_CHANNEL_SELECTION ==ADC_CHANNEL7
		WRITE_BIT(ADMUX,0,1);
		WRITE_BIT(ADMUX,1,1);
		WRITE_BIT(ADMUX,2,1);
		WRITE_BIT(ADMUX,3,0);
		WRITE_BIT(ADMUX,4,0);
#endif
#endif
//the below values need to be  revised t 100%correct
#if ADC_CHANNEL_MODE ==ADC_DIFFRENTIAL
#if ADC_CHANNEL_SELECTION ==ADC_CHANNEL0
		WRITE_BIT(ADMUX,0,0);
		WRITE_BIT(ADMUX,1,0);
		WRITE_BIT(ADMUX,2,0);
		WRITE_BIT(ADMUX,3,1);
		WRITE_BIT(ADMUX,4,0);

#elif ADC_CHANNEL_SELECTION ==ADC_CHANNEL1
		WRITE_BIT(ADMUX,0,1);
		WRITE_BIT(ADMUX,1,0);
		WRITE_BIT(ADMUX,2,0);
		WRITE_BIT(ADMUX,3,1);
		WRITE_BIT(ADMUX,4,0);

#elif ADC_CHANNEL_SELECTION ==ADC_CHANNEL2
		WRITE_BIT(ADMUX,0,0);
		WRITE_BIT(ADMUX,1,1);
		WRITE_BIT(ADMUX,2,0);
		WRITE_BIT(ADMUX,3,0);
		WRITE_BIT(ADMUX,4,0);
#elif ADC_CHANNEL_SELECTION ==ADC_CHANNEL3
		WRITE_BIT(ADMUX,0,1);
		WRITE_BIT(ADMUX,1,1);
		WRITE_BIT(ADMUX,2,0);
		WRITE_BIT(ADMUX,3,0);
		WRITE_BIT(ADMUX,4,0);
#elif ADC_CHANNEL_SELECTION ==ADC_CHANNEL4
		WRITE_BIT(ADMUX,0,0);
		WRITE_BIT(ADMUX,1,0);
		WRITE_BIT(ADMUX,2,1);
		WRITE_BIT(ADMUX,3,0);
		WRITE_BIT(ADMUX,4,0);
#elif ADC_CHANNEL_SELECTION ==ADC_CHANNEL5
		WRITE_BIT(ADMUX,0,1);
		WRITE_BIT(ADMUX,1,0);
		WRITE_BIT(ADMUX,2,1);
		WRITE_BIT(ADMUX,3,0);
		WRITE_BIT(ADMUX,4,0);
#elif ADC_CHANNEL_SELECTION ==ADC_CHANNEL6
		WRITE_BIT(ADMUX,0,0);
		WRITE_BIT(ADMUX,1,1);
		WRITE_BIT(ADMUX,2,1);
		WRITE_BIT(ADMUX,3,0);
		WRITE_BIT(ADMUX,4,0);
#elif ADC_CHANNEL_SELECTION ==ADC_CHANNEL7
		WRITE_BIT(ADMUX,0,1);
		WRITE_BIT(ADMUX,1,1);
		WRITE_BIT(ADMUX,2,1);
		WRITE_BIT(ADMUX,3,0);
		WRITE_BIT(ADMUX,4,0);
#endif

#endif

		WRITE_BIT(ADCSRA,7,1);
#if ADC_USAGE==ADC_INTERRUPT
		WRITE_BIT(ADCCSRA,3,1);
#endif
#if ADC_PRESCALER ==ADC_PRESCALER_2
		        WRITE_BIT(ADCSRA,0,0);
				WRITE_BIT(ADCSRA,1,0);
				WRITE_BIT(ADCSRA,2,0);

#elif ADC_PRESCALER ==ADC_PRESCALER_4
		        WRITE_BIT(ADCSRA,0,0);
				WRITE_BIT(ADCSRA,1,1);
				WRITE_BIT(ADCSRA,2,0);

#elif ADC_PRESCALER ==ADC_PRESCALER_8
		        WRITE_BIT(ADCSRA,0,1);
				WRITE_BIT(ADCSRA,1,1);
				WRITE_BIT(ADCSRA,2,0);

#elif ADC_PRESCALER ==ADC_PRESCALER_16
		        WRITE_BIT(ADCSRA,0,0);
				WRITE_BIT(ADCSRA,1,0);
				WRITE_BIT(ADCSRA,2,1);

#elif ADC_PRESCALER ==ADC_PRESCALER_32
		        WRITE_BIT(ADCSRA,0,1);
				WRITE_BIT(ADCSRA,1,0);
				WRITE_BIT(ADCSRA,2,1);
#elif ADC_PRESCALER ==ADC_PRESCALER_64
		        WRITE_BIT(ADCSRA,0,0);
				WRITE_BIT(ADCSRA,1,1);
				WRITE_BIT(ADCSRA,2,1);
#elif ADC_PRESCALER ==ADC_PRESCALER_128
		        WRITE_BIT(ADCSRA,0,1);
				WRITE_BIT(ADCSRA,1,1);
				WRITE_BIT(ADCSRA,2,1);
#endif

#if ADC_CONVERSION ==ADC_FREE_RUNNING
				 WRITE_BIT(SFIOR,5,0);
				 WRITE_BIT(SFIOR,6,0);
				 WRITE_BIT(SFIOR,7,0);
//The rest of auto trigeer sources to be comleted
#endif
}
u16 ADC_u8Getvalue()
{
u16 local_u8value=0;
#if ADC_ADJUSTMENT ==ADC_RIGHT
local_u8value=ADCL+ADCH<<8;
return local_u8value;
#elif ADC_ADJUSTMENT ==ADC_LEFT
local_u8value=(ADCH<<2);
return local_u8value;
#endif
}
void ADC_voidStartConversion()
{


	WRITE_BIT(ADCSRA,6,1);

}
u8 ADC_u8CheckFlag()
{


	return GET_BIT(ADCSRA,4);

}
