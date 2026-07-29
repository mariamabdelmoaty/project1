#include "../00_lib/std_types.h"
#include "../00_lib/bit_math.h"

#include "../01_mcal/dio/dio_interface.h"
#include "../01_mcal/adc/adc_interface.h"

#include "../02_hal/lcd_i2c/lcd_interface.h"
#include "../02_hal/buzzer/buzzer_interface.h"

#include "app_interface.h"

static Buzzer_t AlarmBuzzer = {DIO_PORTC, DIO_PIN5};

void APP_vInit(void)
{
    /* Initialize Drivers */
    ADC_vInit();
    LCD_vInit();
    BUZZER_vInit(&AlarmBuzzer);

    /* Welcome Message on LCD */
    LCD_vSetCursor(0, 0);
    LCD_vSendString((u8*)"Solar Controller");
    LCD_vSetCursor(1, 0);
    LCD_vSendString((u8*)"System Ready...");
}

void APP_vUpdateSystem(void)
{
    /* Read Voltage & Current from Solar Panel (ADC Channels 0 & 1) */
    u16 Local_u16SolarVolt = ADC_u16ReadChannel(ADC_CHANNEL_0);
    u16 Local_u16SolarCurr = ADC_u16ReadChannel(ADC_CHANNEL_1);

    /* Check Over-Voltage Protection (Example Threshold) */
    if(Local_u16SolarVolt > 800)
    {
        BUZZER_vTurnOn(&AlarmBuzzer);
        LCD_vSetCursor(1, 0);
        LCD_vSendString((u8*)"OVER VOLTAGE!   ");
    }
    else
    {
        BUZZER_vTurnOff(&AlarmBuzzer);
    }
}