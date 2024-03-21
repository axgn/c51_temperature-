#include <REGX52.H>
#include "i2cwire.h"
#define AT24C02_ADDR 0xA0 //write

void AT24C02_Write(unsigned char Addr, unsigned char Data)
{
    unsigned char ACK;
    I2C_Start();
    I2C_SendByte(AT24C02_ADDR);
    ACK = I2C_ReceiveAck();
    I2C_SendByte(Addr);
    ACK = I2C_ReceiveAck();
    I2C_SendByte(Data);
    ACK = I2C_ReceiveAck();
    I2C_Stop();
}

unsigned char AT24C02_Read(unsigned char Addr)
{
    unsigned char Data;
    I2C_Start();
    I2C_SendByte(AT24C02_ADDR);
    I2C_ReceiveAck();
    I2C_SendByte(Addr);
    I2C_ReceiveAck();
    I2C_Start();
    I2C_SendByte(AT24C02_ADDR | 0x01);
    I2C_ReceiveAck();
    Data = I2C_ReceiveByte();
    I2C_SendAck(0);
    I2C_Stop();
    return Data;
}