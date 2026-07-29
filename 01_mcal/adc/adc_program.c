#include "../../00_lib/std_types.h"
#include "../../00_lib/bit_math.h"

#include "ADC_private.h"
#include "ADC_interface.h"

void ADC_vInit(void)
{
    /* AVCC with external capacitor at AREF pin */
    SET_BIT(ADMUX, 6);
    CLR_BIT(ADMUX, 7);

    /* Enable ADC & Prescaler = 128 */
    SET_BIT(ADCSRA, 7);
    SET_BIT(ADCSRA, 2);
    SET_BIT(ADCSRA, 1);
    SET_BIT(ADCSRA, 0);
}

u16 ADC_u16ReadChannel(u8 Copy_u8Channel)
{
    /* Select Channel */
    ADMUX = (ADMUX & 0xE0) | (Copy_u8Channel & 0x07);

    /* Start Conversion */
    SET_BIT(ADCSRA, 6);

    /* Wait for conversion to complete */
    while(GET_BIT(ADCSRA, 4) == 0);

    /* Clear Interrupt Flag */
    SET_BIT(ADCSRA, 4);

    return ADC_DATA_REG;
}