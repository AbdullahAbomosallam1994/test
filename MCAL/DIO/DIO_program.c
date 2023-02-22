#include "DIO_registers.h"
#include "DIO_interface.h"
#include"DIO_interface.h"
/*******************Library bit manupilation*********************/
#define SET_BIT(REG,BIT)          (REG|=(1<<BIT))   
#define CLR_BIT(REG,BIT)          (REG&= ~(1<<BIT))
#define GET_BIT(REG,BIT)          ((REG>>BIT)&1)
#define TOGGLE_BIT(REG,BIT)       (REG^=(1<<BIT))
#define WRITE_BIT(REG,BIT,VALUE)  (REG = (VALUE<<BIT) | (REG&~(1<<BIT))  


/*******************Functions' implementation********************/

u8 DIO_u8SetPinDirection(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Direction)
{
	/*local variable for error indication , initially = 0*/
	u8 Local_u8ErrorState = 0 ;
	
	/*checking for existing in the correct range of pins*/
	if((Copy_u8PinID>=0 && Copy_u8PinID<=7))
	{
		/*switching over ports*/
		switch(Copy_u8PortID)
        {
			/*in case of setting direction of a pin in port A*/
			case PORTA :
				/*switching over different pins directions*/
				switch(Copy_u8Direction)
				{
					case DIO_PIN_OUT :
						WRITE_BIT(DIO_DDRA , Copy_u8PinID , 1) ;
						break ;
						
					case DIO_PIN_INPUT_FLOAT :
						WRITE_BIT(DIO_DDRA , Copy_u8PinID , 0) ;
						break ;
					
					case DIO_PIN_INPUT_PULLUP :
						WRITE_BIT(DIO_DDRA , Copy_u8PinID  , 0) ;
						WRITE_BIT(DIO_PORTA , Copy_u8PinID , 1) ;
						break ;
						
					default ;
						/*error of wrong direction input argument*/
						Local_u8ErrorState = 2 ;
				}	
				
				/*break from case of PORTA*/
				break ;
				
			/*****************************************************/
			
			/*in case of setting direction of a pin in port B*/
			case PORTB :
			
				/*switching over different pins directions*/
				switch(Copy_u8Direction)
				{
					case DIO_PIN_OUT :
						WRITE_BIT(DIO_DDRB , Copy_u8PinID , 1) ;
						break ;
						
					case DIO_PIN_INPUT_FLOAT :
						WRITE_BIT(DIO_DDRB , Copy_u8PinID , 0) ;
						break ;
					
					case DIO_PIN_INPUT_PULLUP :
						WRITE_BIT(DIO_DDRB , Copy_u8PinID  , 0) ;
						WRITE_BIT(DIO_PORTB , Copy_u8PinID , 1) ;
						break ;
						
					default ;
						/*error of wrong direction input argument*/
						Local_u8ErrorState = 2 ;
				}	
				
				/*break from case of PORTB*/
				break ;
			

			/**********************************************************/
			
			/*in case of setting direction of a pin in port C*/
			case PORTC :
			
				/*switching over different pins directions*/
				switch(Copy_u8Direction)
				{
					case DIO_PIN_OUT :
						WRITE_BIT(DIO_DDRC , Copy_u8PinID , 1) ;
						break ;
						
					case DIO_PIN_INPUT_FLOAT :
						WRITE_BIT(DIO_DDRC , Copy_u8PinID , 0) ;
						break ;
					
					case DIO_PIN_INPUT_PULLUP :
						WRITE_BIT(DIO_DDRC , Copy_u8PinID  , 0) ;
						WRITE_BIT(DIO_PORTC , Copy_u8PinID , 1) ;
						break ;
						
					default ;
						/*error of wrong direction input argument*/
						Local_u8ErrorState = 2 ;
				}	
				
				/*break from case of PORTC*/
				break ;
				
			/*****************************************************/
		
			/*in case of setting direction of a pin in port A*/
			case PORTD :
			
				/*switching over different pins directions*/
				switch(Copy_u8Direction)
				{
					case DIO_PIN_OUT :
						WRITE_BIT(DIO_DDRD , Copy_u8PinID , 1) ;
						break ;
						
					case DIO_PIN_INPUT_FLOAT :
						WRITE_BIT(DIO_DDRD , Copy_u8PinID , 0) ;
						break ;
					
					case DIO_PIN_INPUT_PULLUP :
						WRITE_BIT(DIO_DDRD , Copy_u8PinID  , 0) ;
						WRITE_BIT(DIO_PORTD , Copy_u8PinID , 1) ;
						break ;
						
					default ;
						/*error of wrong direction input argument*/
						Local_u8ErrorState = 2 ;
				}	
				
				/*break from case of PORTD*/
				break ;
				
			/*****************************************************/
			
			/*in case of wrong input argument*/	
			default :
				/*error of wrong portID input argument*/
				Local_u8ErrorState = 3 ;
				break ;
				
		}
	}
	
	else
	{
		/*error of wrong pin input argument*/
		Local_u8ErrorState = 1 ;
	}
	
	/*return from this function*/
	return Local_u8ErrorState ;
	
}
	
/***************************************************************************************************************************/
	
u8 DIO_u8SetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Direction)
{
	/*local variable for error indication , initially = 0*/
	u8 Local_u8ErrorState = 0 ;
	
	/*checking for existing in the correct range of pins*/
	if( (Copy_u8PinID>=0 && Copy_u8PinID<=7))
	{
		/*checking for valid pin value input argument*/
		if(Copy_u8Direction==DIO_HIGH_PIN || Copy_u8Direction==DIO_LOW_PIN) 
		{
			/*switching over ports*/
			switch(Copy_u8PortID)
			{
				case PORTA :
					WRITE_BIT(DIO_PORTA,Copy_u8PinID,Copy_u8Direction);
					break;
				
				case PORTB :
					WRITE_BIT(DIO_PORTB,Copy_u8PinID,Copy_u8Direction);
					break;
				
				case PORTC :
					WRITE_BIT(DIO_PORTC,Copy_u8PinID,Copy_u8Direction);
					break;
				
				case PORTD :
					WRITE_BIT(DIO_PORTD,Copy_u8PinID,Copy_u8Direction);		
					break;
				
				/*in case of wrong portID input argument*/
				default :
					Local_u8ErrorState = 3 ;
					break;
			}	
		}
		else
			/*error of wrong pin value input argument*/
			Local_u8ErrorState = 2 ;
	}
	
	else
	{
		/*error of wrong pin input argument*/
		Local_u8ErrorState = 1 ;
	}

	/*return from this function*/
	return Local_u8ErrorState ;	
}	

/***************************************************************************************************************************/

u8 DIO_u8SetPortDirection(u8 Copy_u8PortID , u8 Copy_u8Direction)
{
	/*local variable for error indication , initially = 0 */
	u8 Local_u8ErrorState = 0 ;
	
	/*switching over different ports*/
	switch(Copy_u8PortID)
	{
		case PORTA :
			/*switching over port directions*/
			switch(Copy_u8Direction)
			{
				case DIO_PORT_OUT :			    DIO_DDRA = 0xFF ;		break ;
				
				case DIO_PORT_INPUT_FLOAT :    	DIO_DDRA = 0x00 ;		break ;
				
				case DIO_PORT_INPUT_PULLUP :    DIO_DDRA = 0x00;
												DIO_PORTA= 0xFF;		break ;
				
				default :                       
					/*error of wrong direction input argument*/
					Local_u8ErrorState = 2 ;
					break ;
			}	
		
		/*break from case of portA*/		
		break;
		
		case PORTB :
			/*switching over port directions*/
			switch(Copy_u8Direction)
			{
				case DIO_PORT_OUT :			    DIO_DDRB = 0xFF ;		break ;
				
				case DIO_PORT_INPUT_FLOAT :    	DIO_DDRB = 0x00 ;		break ;
				
				case DIO_PORT_INPUT_PULLUP :    DIO_DDRB = 0x00;
												DIO_PORTB= 0xFF;		break ;
				
				default :                       
					/*error of wrong direction input argument*/
					Local_u8ErrorState = 2 ;
					break ;
			}	
		
		/*break from case of portB*/		
		break;
		
		case PORTC :
			/*switching over port directions*/
			switch(Copy_u8Direction)
			{
				case DIO_PORT_OUT :			    DIO_DDRC = 0xFF ;		break ;
				
				case DIO_PORT_INPUT_FLOAT :    	DIO_DDRC = 0x00 ;		break ;
				
				case DIO_PORT_INPUT_PULLUP :    DIO_DDRC = 0x00;
												DIO_PORTC= 0xFF;		break ;
				
				default :                       
					/*error of wrong direction input argument*/
					Local_u8ErrorState = 2 ;
					break ;
			}	
		
		/*break from case of portC*/		
		break;
		
		case PORTD :
			/*switching over port directions*/
			switch(Copy_u8Direction)
			{
				case DIO_PORT_OUT :			    DIO_DDRD = 0xFF ;		break ;
				
				case DIO_PORT_INPUT_FLOAT :    	DIO_DDRD = 0x00 ;		break ;
				
				case DIO_PORT_INPUT_PULLUP :    DIO_DDRD = 0x00;
												DIO_PORTD= 0xFF;		break ;
				
				default :                       
					/*error of wrong direction input argument*/
					Local_u8ErrorState = 2 ;
					break ;
			}	
		
		/*break from case of portD*/		
		break;
		
		/*in case of wrong portID input argument*/
		default :	Local_u8ErrorState = 1 ;       break ;
	}	
			
	/*return from this function*/
	return Local_u8ErrorState ;
}

/***************************************************************************************************************************/
	
u8 DIO_u8SetPortValue(u8 Copy_u8PortID , u8 Copy_u8Value)
{
		/*local variable for error indication , initially = 0*/
		u8 Local_u8ErrorState = 0 ;
		
		/*checking for valid input value range[0:255]*/
		if(Copy_u8Value>=0 && Copy_u8Value<=255)
		{
			/*switching over ports*/
			switch(Copy_u8PortID)
			{
				case PORTA :     DIO_PORTA = Copy_u8Value ;    	break ;
				
				case PORTB :     DIO_PORTB = Copy_u8Value ;    	break ;
				
				case PORTC :     DIO_PORTC = Copy_u8Value ;    	break ;
				
				case PORTD :     DIO_PORTD = Copy_u8Value ;    	break ;	
				
				/*in case of error of wrong port ID input argument*/
				default :        Local_u8ErrorState = 1 ; 		break ;	
			}			
		}
		
		else
			/*error of input value out of valid range*/
			Local_u8ErrorState = 2 ;
		
		/*return from this function*/
		return Local_u8ErrorState; 	
}

/***************************************************************************************************************************/

u8 DIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
	/*Local variable to store the value of the pin*/
	u8 Local_u8PinValue = DIO_LOW_PIN ;
	
	/*switching over ports*/
	switch(Copy_u8PortID)
	{
		case PORTA :	
			Local_u8PinValue = GET_BIT(DIO_PINA, Copy_u8PinID); 
			break ;
		
		case PORTB :    
			Local_u8PinValue = GET_BIT(DIO_PINB, Copy_u8PinID); 
			break ;

		case PORTC :   
			Local_u8PinValue = GET_BIT(DIO_PINB, Copy_u8PinID); 
			break ;

		case PORTD :   
			Local_u8PinValue = GET_BIT(DIO_PINB, Copy_u8PinID); 
			break ;

		default :       /*do nothing*/  break ;
	}

	/*return form this function*/
	return Local_u8PinValue ;	
}	

/***************************************************************************************************************************/

u8 DIO_u8TogglePin(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
	/*local variable for error indication , initially = 0*/
	u8 Local_u8ErrorState = 0 ;
	
	/*checking for existing in the valid range of pins*/
	if(Copy_u8PinID>=0 && Copy_u8PinID<=7)
	{
		switch(Copy_u8PortID)
		{
			case PORTA :	TOGGLE_BIT(DIO_PORTA,Copy_u8PinID);		break ;
			
			case PORTB :	TOGGLE_BIT(DIO_PORTB,Copy_u8PinID);		break ;
	
			case PORTC :	TOGGLE_BIT(DIO_PORTC,Copy_u8PinID);		break ;
			
			case PORTD :	TOGGLE_BIT(DIO_PORTD,Copy_u8PinID);		break ;
			
			/*in case of wrong portID*/
			default :       Local_u8ErrorState = 1 ; 				break ;
		}	
	}
	
	else
		/*in case of error of pinID*/
		Local_u8ErrorState = 2 ;
	
	/*return from this function*/
	return Local_u8ErrorState ;
}
	



