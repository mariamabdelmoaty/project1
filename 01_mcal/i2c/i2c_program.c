#include "../../00_lib/std_types.h"
#include "../../00_lib/bit_math.h"

#include "I2C_private.h"
#include "I2C_interface.h"

void I2C_vInitMaster(void)
{
    /* Set Bit Rate for 100kHz Frequency at 8MHz F_CPU */
    TWBR = 32;
    TWSR = 0x00; // Prescaler = 1
    
    /* Enable TWI */
    SET_BIT(TWCR, 2);
}

void I2C_vSendStart(void)
{
    /* Clear TWINT, Set TWSTA (Start), Enable TWI */
    TWCR = (1 << 7) | (1 << 5) | (1 << 2);
    
    /* Wait for flag */
    while(GET_BIT(TWCR, 7) == 0);
}

void I2C_vSendByte(u8 Copy_u8Data)
{
    TWDR = Copy_u8Data;
    /* Clear TWINT, Enable TWI */
    TWCR = (1 << 7) | (1 << 2);
    
    /* Wait for flag */
    while(GET_BIT(TWCR, 7) == 0);
}

u8 I2C_u8ReadByteWithACK(void)
{
    /* Clear TWINT, Enable TWI, Enable TWEA (ACK) */
    TWCR = (1 << 7) | (1 << 2) | (1 << 6);
    
    /* Wait for flag */
    while(GET_BIT(TWCR, 7) == 0);
    
    return TWDR;
}

void I2C_vSendStop(void)
{
    /* Clear TWINT, Set TWSTO (Stop), Enable TWI */
    TWCR = (1 << 7) | (1 << 4) | (1 << 2);
}