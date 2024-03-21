#ifndef __I2CWIRE_H__
#define __I2CWIRE_H__

void I2C_Start(void);
void I2C_Stop(void);
void I2C_SendByte(unsigned char Byte);
unsigned char I2C_ReceiveByte(void);
unsigned char I2C_ReceiveAck(void);
void I2C_SendAck(unsigned char Ack_bit);

#endif