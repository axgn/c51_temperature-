#include <REGX52.H>
#include <intrins.h>

sbit OneWire_DQ = P3^7;

unsigned char OneWire_Init(void)
{
	unsigned char i;
	unsigned char AckBit;
	OneWire_DQ = 1;
	OneWire_DQ = 0;
	_nop_();
	i = 227;while (--i); //Delay 500us
	OneWire_DQ = 1;
	_nop_();
	i = 29;while (--i);
	AckBit = OneWire_DQ; //get value from follow machine
	_nop_();
	i = 227;while (--i);// end the time series
	return AckBit;
}

void OneWire_SendBit(unsigned char Bit)
{
	unsigned char i;
	OneWire_DQ = 0;
	i  = 4;while (--i);
	OneWire_DQ = Bit;
	i  = 24;while (--i);
	OneWire_DQ = 1;
}

unsigned char OneWire_ReceiveBit(void)
{
	unsigned char Bit;
	unsigned char i;
	OneWire_DQ = 0;
	i = 2;while (--i);
	OneWire_DQ = 1;
	i = 2;while (--i);
	Bit = OneWire_DQ;
	i = 24;while (--i);
	return Bit;
}

void OneWire_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i = 0;i < 8;i++)
	{
		OneWire_SendBit(Byte&(0x01 << i));
	}
}

unsigned char OneWire_ReceiveByte(void)
{
	unsigned char i;
	unsigned char Byte = 0x00;
	for(i = 0;i < 8;i++)
	{
		if(OneWire_ReceiveBit())
		{Byte |= (0x01 << i);}
	}
	return Byte;
}