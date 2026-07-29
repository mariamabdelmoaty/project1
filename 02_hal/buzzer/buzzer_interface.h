#ifndef BUZZER_INTERFACE_H_
#define BUZZER_INTERFACE_H_

#include "../../00_lib/std_types.h"

typedef struct
{
    u8 Port;
    u8 Pin;
} Buzzer_t;

void BUZZER_vInit(Buzzer_t *Copy_pstructBuzzer);
void BUZZER_vTurnOn(Buzzer_t *Copy_pstructBuzzer);
void BUZZER_vTurnOff(Buzzer_t *Copy_pstructBuzzer);

#endif /* BUZZER_INTERFACE_H_ */