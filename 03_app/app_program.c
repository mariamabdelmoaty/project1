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
    /* Read Voltage from R1 connected to ADC Channel 0 */
    u16 Local_u16R1Val = ADC_u16ReadChannel(ADC_CHANNEL_0);
    
    /* Convert ADC value directly to percentage based on R1 movement */
    u8 r1_percentage = (u8)((Local_u16R1Val * 100UL) / 1023UL);

    /* Display result on LCD second line */
    u8 buffer[16];
    LCD_vSetCursor(1, 0);
    sprintf(buffer, "R1: %d%%      ", r1_percentage);
    LCD_vSendString(buffer);
}