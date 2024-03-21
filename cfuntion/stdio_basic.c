#include <REG52.H>

void UartInit(void)
{
    PCON &= 0x7F;
    SCON = 0x50;
    TMOD &= 0x0F;
    TMOD |= 0x20;
    TL1 = 0xFD;
    TH1 = 0xFD;
    ET1 = 0;
    TR1 = 1;
}

void sendByte(unsigned char dat)
{
    SBUF = dat;
    while (!TI)
        ;
    TI = 0;
}

char putchar(char c)
{
    sendByte(c);
    return c;
}