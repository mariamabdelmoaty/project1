#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "../../00_lib/std_types.h"

/* Port Defines */
#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3

/* Pin Defines */
#define DIO_PIN0     0
#define DIO_PIN1     1
#define DIO_PIN2     2
#define DIO_PIN3     3
#define DIO_PIN4     4
#define DIO_PIN5     5
#define DIO_PIN6     6
#define DIO_PIN7     7

/* Direction Defines */
#define DIO_INPUT    0
#define DIO_OUTPUT   1

/* Value Defines */
#define DIO_LOW      0
#define DIO_HIGH     1

/* Function Prototypes */
void DIO_vSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
void DIO_vSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8   DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

void DIO_vSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
void DIO_vSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

#endif /* DIO_INTERFACE_H_ */