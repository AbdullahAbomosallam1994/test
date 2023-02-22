#include"../SERVICES/STD_TYPES.h"
#include"../DIO/DIO_interface.h"


#define BUZZER_FORWARD 1
#define BUZZER_REVERSE 0

#define BUZZER_PORTA  0
#define BUZZER_PORTB  1
#define BUZZER_PORTC  2
#define BUZZER_PORTD  3


#define BUZZER_PIN0   0
#define BUZZER_PIN1   1
#define BUZZER_PIN2   2
#define BUZZER_PIN3   3
#define BUZZER_PIN4   4
#define BUZZER_PIN5   5
#define BUZZER_PIN6   6
#define BUZZER_PIN7   7



typedef struct 
{
	u8 port;
	u8 pin ;
	u8 connection;
	
} BUZZER_TYPE;

void BUZZER_voidLedOn(BUZZER_TYPE copy_BuzzerStructled1);
void BUZZER_voidLedOff(BUZZER_TYPE copy_BuzzerStructled1);
void BUZZER_voidInit(BUZZER_TYPE copy_BuzzerStructled1);