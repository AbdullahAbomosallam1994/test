
#include"LED_interface.h"
#include"../MCAL/DIO/DIO_interface.h"

void DCM_voidDCMOn(DCM_TYPE copy_DCMStructDCM1)

{
	if(copy_DCMStructDCM1.connection==DCM_FORWARD)
DIO_u8SetPinValue(copy_DCMStructDCM1.port,copy_DCMStructDCM1.pin,DIO_HIGH);
	else if(copy_DCMStructDCM1.connection==DCM_REVERSE)
DIO_u8SetPinValue(copy_DCMStructDCM1.port,copy_DCMStructDCM1.pin,DIO_LOW);	
	
	
}
void DCM_voidLedOff(DCM_TYPE copy_DCMStructDCM1)
{
	
	
	if(copy_DCMStructDCM1.connection==LED_FORWARD)
DIO_u8SetPinValue(copy_DCMStructDCM1.port,copy_DCMStructDCM1.pin,DIO_LOW);
	else if(copy_DCMStructDCM1.connection==LED_REVERSE)
DIO_u8SetPinValue(copy_DCMStructDCM1.port,copy_DCMStructDCM1.pin,DIO_HIGH);	
	
	
	
	
}
void DCM_voidInit(DCM_TYPE copy_DCMStructDCM1)
{
	
	DIO_u8SetPinDirection(copy_DCMStructDCM1.port,copy_DCMStructDCM1.pin, DIO_OUTPUT);
	
	
	
	
	
	
}



