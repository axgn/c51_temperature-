#include <REGX52.H>

sbit I2C_SDA = P2 ^ 0;
sbit I2C_SCL = P2 ^ 1;

/**
 * @brief I2C开始信号
 *
 *
 *
 */
void I2C_Start(void)
{
    I2C_SCL = 1;
    I2C_SDA = 1;
    I2C_SDA = 0;
    I2C_SCL = 0;
}

/**
 * @brief I2C结束信号
 *
 *
 *
 */
void I2C_Stop(void)
{
    I2C_SDA = 0;
    I2C_SCL = 1;
    I2C_SDA = 1;
}
/**
 * @brief I2C发送一个字节
 *
 * @param Byte 传入要发送的字节
 *
 */
void I2C_SendByte(unsigned char Byte)
{
    unsigned char i;
    for (i = 0; i < 8; i++)
    {
        I2C_SDA = Byte & (0x80 >> i);
        I2C_SCL = 1;
        I2C_SCL = 0;
    }
}

/**
 * @brief I2C接收一个字节
 *
 * @return unsigned char 接收到的字节
 *
 */
unsigned char I2C_ReceiveByte(void)
{
    unsigned char i, Byte = 0;

    I2C_SDA = 1;

    for (i = 0; i < 8; i++)
    {
        I2C_SCL = 1;
        if (I2C_SDA)
            Byte |= 0x80 >> i;
        I2C_SCL = 0;
    }
    return Byte;
}
/**
 * @brief I2C接收一个字节的应答
 *
 * @return unsigned char 接收到的应答
 *
 */
unsigned char I2C_ReceiveAck(void)
{
    unsigned char Ack_bit;
    I2C_SDA = 1;
    I2C_SCL = 1;
    Ack_bit = I2C_SDA;
    I2C_SCL = 0;
    return ~Ack_bit;
}

/**
 * @brief I2C发送应答
 *
 * @param Ack_bit 传入应答
 *
 */
void I2C_SendAck(unsigned char Ack_bit)
{
    I2C_SDA = ~Ack_bit;
    I2C_SCL = 1;
    I2C_SCL = 0;
}