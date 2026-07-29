#include "../../00_lib/std_types.h"
#include "../../00_lib/bit_math.h"

#include "../../01_mcal/dio/dio_interface.h"
#include "button_interface.h"

u8 BUTTON_u8GetState(Button_t *Copy_pstructButton)
{
    u8 Local_u8PinVal = DIO_u8GetPinValue(Copy_pstructButton->Port, Copy_pstructButton->Pin);
    u8 Local_u8State  = BUTTON_RELEASED;

    if(Copy_pstructButton->ActiveState == BUTTON_ACTIVE_HIGH)
    {
        if(Local_u8PinVal == 1)
        {
            Local_u8State = BUTTON_PRESSED;
        }
    }
    else if(Copy_pstructButton->ActiveState == BUTTON_ACTIVE_LOW)
    {
        if(Local_u8PinVal == 0)
        {
            Local_u8State = BUTTON_PRESSED;
        }
    }

    return Local_u8State;
}