#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "../../00_lib/std_types.h"

void LCD_vInit(void);
void LCD_vSendCmd(u8 Copy_u8Cmd);
void LCD_vSendChar(u8 Copy_u8Data);
void LCD_vSendString(u8 *Copy_u8Str);
void LCD_vSetCursor(u8 Copy_u8Row, u8 Copy_u8Col);
void LCD_vClear(void);

#endif /* LCD_INTERFACE_H_ */