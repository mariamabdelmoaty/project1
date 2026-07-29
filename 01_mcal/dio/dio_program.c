#include "../../00_LIB/STD_TYPES.h"
#include "../../00_LIB/BIT_MATH.h"

#include "DIO_private.h"
#include "DIO_interface.h"

void DIO_vSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
    if(Copy_u8Pin <= DIO_PIN7)
    {
        if(Copy_u8Direction == DIO_OUTPUT)
        {
            switch(Copy_u8Port)
            {
                case DIO_PORTA: SET_BIT(DDRA, Copy_u8Pin); break;
                case DIO_PORTB: SET_BIT(DDRB, Copy_u8Pin); break;
                case DIO_PORTC: SET_BIT(DDRC, Copy_u8Pin); break;
                case DIO_PORTD: SET_BIT(DDRD, Copy_u8Pin); break;
            }
        }
        else if(Copy_u8Direction == DIO_INPUT)
        {
            switch(Copy_u8Port)
            {
                case DIO_PORTA: CLR_BIT(DDRA, Copy_u8Pin); break;
                case DIO_PORTB: CLR_BIT(DDRB, Copy_u8Pin); break;
                case DIO_PORTC: CLR_BIT(DDRC, Copy_u8Pin); break;
                case DIO_PORTD: CLR_BIT(DDRD, Copy_u8Pin); break;
            }
        }
    }
}

void DIO_vSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
    if(Copy_u8Pin <= DIO_PIN7)
    {
        if(Copy_u8Value == DIO_HIGH)
        {
            switch(Copy_u8Port)
            {
                case DIO_PORTA: SET_BIT(PORTA, Copy_u8Pin); break;
                case DIO_PORTB: SET_BIT(PORTB, Copy_u8Pin); break;
                case DIO_PORTC: SET_BIT(PORTC, Copy_u8Pin); break;
                case DIO_PORTD: SET_BIT(PORTD, Copy_u8Pin); break;
            }
        }
        else if(Copy_u8Value == DIO_LOW)
        {
            switch(Copy_u8Port)
            {
                case DIO_PORTA: CLR_BIT(PORTA, Copy_u8Pin); break;
                case DIO_PORTB: CLR_BIT(PORTB, Copy_u8Pin); break;
                case DIO_PORTC: CLR_BIT(PORTC, Copy_u8Pin); break;
                case DIO_PORTD: CLR_BIT(PORTD, Copy_u8Pin); break;
            }
        }
    }
}

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin)
{
    u8 Local_u8Result = 0;
    if(Copy_u8Pin <= DIO_PIN7)
    {
        switch(Copy_u8Port)
        {
            case DIO_PORTA: Local_u8Result = GET_BIT(PINA, Copy_u8Pin); break;
            case DIO_PORTB: Local_u8Result = GET_BIT(PINB, Copy_u8Pin); break;
            case DIO_PORTC: Local_u8Result = GET_BIT(PINC, Copy_u8Pin); break;
            case DIO_PORTD: Local_u8Result = GET_BIT(PIND, Copy_u8Pin); break;
        }
    }
    return Local_u8Result;
}

void DIO_vSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
    switch(Copy_u8Port)
    {
        case DIO_PORTA: DDRA = Copy_u8Direction; break;
        case DIO_PORTB: DDRB = Copy_u8Direction; break;
        case DIO_PORTC: DDRC = Copy_u8Direction; break;
        case DIO_PORTD: DDRD = Copy_u8Direction; break;
    }
}

void DIO_vSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
    switch(Copy_u8Port)
    {
        case DIO_PORTA: PORTA = Copy_u8Value; break;
        case DIO_PORTB: PORTB = Copy_u8Value; break;
        case DIO_PORTC: PORTC = Copy_u8Value; break;
        case DIO_PORTD: PORTD = Copy_u8Value; break;
    }
}