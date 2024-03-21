#include "reg52.h"			 
#include "delay.h"

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

unsigned char code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void DigDisplay(unsigned char i,unsigned char zhi)
{
		switch(i)	 
		{
			case(1):
				LSA=0;LSB=0;LSC=0; break;
			case(2):
				LSA=1;LSB=0;LSC=0; break;
			case(3):
				LSA=0;LSB=1;LSC=0; break;
			case(4):
				LSA=1;LSB=1;LSC=0; break;
			case(5):
				LSA=0;LSB=0;LSC=1; break;
			case(6):
				LSA=1;LSB=0;LSC=1; break;
			case(7):
				LSA=0;LSB=1;LSC=1; break;
			case(8):
				LSA=1;LSB=1;LSC=1; break;
		}
		P0=smgduan[zhi];
		Delayms_11(1); 
		P0=0x00;
}