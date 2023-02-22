#include"../SERVICES/STD_TYPES.h"
#include"../DIO/DIO_interface.h"


#define LED_FORWARD 1
#define LED_REVERSE 0

#define LED_PORTA  0
#define LED_PORTB  1
#define LED_PORTC  2
#define LED_PORTD  3


#define LED_PIN0   0
#define LED_PIN1   1
#define LED_PIN1   2
#define LED_PIN3   3
#define LED_PIN4   4
#define LED_PIN5   5
#define LED_PIN6   6
#define LED_PIN7   7


#define LED

typedef struct 
{
	u8 port;
	u8 pin ;
	u8 connection;
	
} LED_TYPE;

void LED_voidLedOn(LED_TYPE copy_LedStructled1);
void LED_voidLedOff(LED_TYPE copy_LedStructled1);
void LED_voidInit(LED_TYPE copy_LedStructled1);