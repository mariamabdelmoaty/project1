#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

#include "../../00_lib/std_types.h"

#define BUTTON_PRESSED      1
#define BUTTON_RELEASED     0

#define BUTTON_ACTIVE_HIGH  1
#define BUTTON_ACTIVE_LOW   0

typedef struct
{
    u8 Port;
    u8 Pin;
    u8 ActiveState;
} Button_t;

u8 BUTTON_u8GetState(Button_t *Copy_pstructButton);

#endif /* BUTTON_INTERFACE_H_ */