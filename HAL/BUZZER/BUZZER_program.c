
#include"BUZZER_interface.h"
#include"../MCAL/DIO/DIO_interface.h"

void BUZZER_voidLedOn(BUZZER_TYPE copy_BuzzerStructBuzzer1)

{
	if(copy_BuzzerStructBuzzer1.connection==BUZZER_FORWARD)
DIO_u8SetPinValue(copy_BuzzerStructBuzzer1.port,copy_BuzzerStructBuzzer1.pin,DIO_HIGH);
	else if(copy_BuzzerStructBuzzer1.connection==LED_REVERSE)
DIO_u8SetPinValue(copy_BuzzerStructBuzzer1.port,copy_BuzzerStructBuzzer1.pin,DIO_LOW);	
	
	
}
void LED_voidLedOff(BUZZER_TYPE copy_BuzzerStructBuzzer1)
{
	
	
	if(copy_BuzzerStructBuzzer1.connection==LED_FORWARD)
DIO_u8SetPinValue(copy_BuzzerStructBuzzer1.port,copy_BuzzerStructBuzzer1.pin,DIO_LOW);
	else if(copy_BuzzerStructBuzzer1.connection==LED_REVERSE)
DIO_u8SetPinValue(copy_BuzzerStructBuzzer1.port,copy_BuzzerStructBuzzer1.pin,DIO_HIGH);	
	
	
	
	
}
void LED_voidInit(BUZZER_TYPE copy_BuzzerStructBuzzer1)
{
	
	DIO_u8SetPinDirection(copy_BuzzerStructBuzzer1.port,copy_BuzzerStructBuzzer1.pin, DIO_OUTPUT);
	
	
	
	
	
	
}



