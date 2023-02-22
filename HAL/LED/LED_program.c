
#include"LED_interface.h"
#include"../MCAL/DIO/DIO_interface.h"

void LED_voidLedOn(LED_TYPE copy_LedStructled1)

{
	if(copy_LedStructled1.connection==LED_FORWARD)
DIO_u8SetPinValue(copy_LedStructled1.port,copy_LedStructled1.pin,DIO_HIGH);
	else if(copy_LedStructled1.connection==LED_REVERSE)
DIO_u8SetPinValue(copy_LedStructled1.port,copy_LedStructled1.pin,DIO_LOW);	
	
	
}
void LED_voidLedOff(LED_TYPE copy_LedStructled1)
{
	
	
	if(copy_LedStructled1.connection==LED_FORWARD)
DIO_u8SetPinValue(copy_LedStructled1.port,copy_LedStructled1.pin,DIO_LOW);
	else if(copy_LedStructled1.connection==LED_REVERSE)
DIO_u8SetPinValue(copy_LedStructled1.port,copy_LedStructled1.pin,DIO_HIGH);	
	
	
	
	
}
void LED_voidInit(LED_TYPE copy_LedStructled1)
{
	
	DIO_u8SetPinDirection(copy_LedStructled1.port,copy_LedStructled1.pin, DIO_OUTPUT);
	
	
	
	
	
	
}



