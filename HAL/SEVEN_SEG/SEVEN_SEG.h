
#include"../SERVICES/STD_TYPES.h"
#include"../DIO/DIO_interface.h"



#define COMMON_CATHOD 1
#define COMMON_ANNODE 0

#define SEVEN_SEG_PORTA  0
#define SEVEN_SEG_PORTB  1
#define SEVEN_SEG_PORTC  2
#define SEVEN_SEG_PORTD  3


#define SEVEN_SEG_PIN0   0
#define SEVEN_SEG_PIN1   1
#define SEVEN_SEG_PIN2   2
#define SEVEN_SEG_PIN3   3
#define SEVEN_SEG_PIN4   4
#define SEVEN_SEG_PIN5   5
#define SEVEN_SEG_PIN6   6
#define SEVEN_SEG_PIN7   7






typedef struct{
	
	u8 port;
	u8 pin;
	u8 connection;
	
	
	
	
}SEVEN_SEG_TYPE;