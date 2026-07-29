#include "../../00_lib/std_types.h"
#include "../../00_lib/bit_math.h"

#include "../../01_mcal/i2c/i2c_interface.h"
#include "lcd_interface.h"

#define LCD_I2C_ADDR  0x40  /* PCF8574 I2C Address */

static void LCD_vWrite4bits(u8 Copy_u8Value)
{
 I2C_vSendStart();
 I2C_vSendByte(LCD_I2C_ADDR);
 I2C_vSendByte(Copy_u8Value | 0x08); /* Backlight ON (Bit 3 = 1) */

 /* Enable Pulse */
 I2C_vSendByte(Copy_u8Value | 0x0C); /* EN = 1 */
 I2C_vSendByte(Copy_u8Value | 0x08); /* EN = 0 */

 I2C_vSendStop();
}

void LCD_vSendCmd(u8 Copy_u8Cmd)
{
 u8 u8HighNibble = Copy_u8Cmd & 0xF0;
 u8 u8LowNibble = (Copy_u8Cmd << 4) & 0xF0;

 LCD_vWrite4bits(u8HighNibble);  /* RS = 0 */
 LCD_vWrite4bits(u8LowNibble);  /* RS = 0 */
}

void LCD_vSendChar(u8 Copy_u8Data)
{
 u8 u8HighNibble = (Copy_u8Data & 0xF0) | 0x01;
 u8 u8LowNibble = ((Copy_u8Data << 4) & 0xF0) | 0x01; /* RS = 1 */

 LCD_vWrite4bits(u8HighNibble);
 LCD_vWrite4bits(u8LowNibble);
}

void LCD_vInit(void)
{
 I2C_vInitMaster();

 /* 4-bit mode Initialization */
 LCD_vSendCmd(0x33);
 LCD_vSendCmd(0x32);
 LCD_vSendCmd(0x28); /* 2 Lines, 5x7 Matrix */
 LCD_vSendCmd(0x0C); /* Display ON, Cursor OFF */
 LCD_vSendCmd(0x06); /* Entry Mode Increment */
 LCD_vClear();
}

void LCD_vSendString(u8 *Copy_u8Str)
{
 u8 Local_u8Index = 0;
 while(Copy_u8Str[Local_u8Index] != '\0')
 {
  LCD_vSendChar(Copy_u8Str[Local_u8Index]);
  Local_u8Index++;
 }
}

void LCD_vSetCursor(u8 Copy_u8Row, u8 Copy_u8Col)
{
 u8 Local_u8Address = 0;
 if(Copy_u8Row == 0) Local_u8Address = 0x80 + Copy_u8Col;
 else if(Copy_u8Row == 1) Local_u8Address = 0xC0 + Copy_u8Col;

 LCD_vSendCmd(Local_u8Address);
}

void LCD_vClear(void)
{
 LCD_vSendCmd(0x01);
}