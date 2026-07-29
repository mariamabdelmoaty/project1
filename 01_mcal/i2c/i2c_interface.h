#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "../../00_lib/std_types.h"

void I2C_vInitMaster(void);
void I2C_vSendStart(void);
void I2C_vSendByte(u8 Copy_u8Data);
u8   I2C_u8ReadByteWithACK(void);
void I2C_vSendStop(void);

#endif /* I2C_INTERFACE_H_ */