#include <intrins.h>

void Delayms(unsigned int xms) //@11.0592MHz
{
    unsigned char i, j;
    while (xms--)
    {
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
}

void Delay10us(unsigned int ums) //@11.0592MHz
{
    while (ums--)
    {
        unsigned char i;

        i = 2;
        while (--i);
    }
}
