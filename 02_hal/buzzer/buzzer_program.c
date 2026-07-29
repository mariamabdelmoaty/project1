#include "../../00_lib/std_types.h"
#include "../../00_lib/bit_math.h"

#include "../../01_mcal/dio/dio_interface.h"
#include "buzzer_interface.h"

void BUZZER_vInit(Buzzer_t *Copy_pstructBuzzer)
{
    DIO_vSetPinDirection(Copy_pstructBuzzer->Port, Copy_pstructBuzzer->Pin, DIO_OUTPUT);
}

void BUZZER_vTurnOn(Buzzer_t *Copy_pstructBuzzer)
{
    DIO_vSetPinValue(Copy_pstructBuzzer->Port, Copy_pstructBuzzer->Pin, DIO_HIGH);
}

void BUZZER_vTurnOff(Buzzer_t *Copy_pstructBuzzer)
{
    DIO_vSetPinValue(Copy_pstructBuzzer->Port, Copy_pstructBuzzer->Pin, DIO_LOW);
}