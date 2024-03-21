//#include "reg51.h"			 
//#include "intrins.h"
//#include "delay.h"
//
//typedef unsigned int u16;	  
//typedef unsigned char u8;
//
//
//sbit SRCLK=P3^6;
//sbit RCLK=P3^5;
//sbit SER=P3^4;
//u8 code wei[]=
//{
//0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80,
//};
//
//u8 code ledwei[]=
//{
//0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 
//};
//
//u8 ledduan1[]=
//{
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
//};
//
//u8 shi[] = {1,3};
//u8 zhong[] = {1,1};
//u16 cnt = 0;
//
//void change1()
//{
//	shi[1] += 1;
//	if(shi[1] >= 8)
//	{
//		shi[0] += 16;
//		shi[1] = 0;
//	}
//	if(shi[0] >= 32)
//	{
//		shi[0] -= 32;
//	}
//}
//void change2()
//{
//	zhong[1] += 1;
//	if(zhong[1] >= 8)
//	{
//		zhong[0] += 16;
//		zhong[1] = 0;
//	}
//	if(zhong[0] >= 32)
//	{
//		zhong[0] -= 32;
//	}
//}
//void change3()
//{
//	shi[0] += 1;
//	if(shi[0] == 15)
//	{
//		shi[0] = 0;
//	}
//	if(shi[0] >= 32)
//	{
//		shi[0] = 16;
//	}
//}
//
//void change4()
//{
//	 zhong[0] += 1;
//	 if(zhong[0] == 15)
//	{
//		zhong[0] = 0;
//	}
//	if(shi[0] >= 32)
//	{
//		zhong[0] = 16;
//	}
//}
//
//void Hc595SendByte(u8 dat1,u8 dat2,u8 dat3,u8 dat4)
//{
//	u8 a;
//
//	SRCLK = 1;
//	RCLK = 1;
//
//	for(a=0;a<8;a++)		 
//	{
//		SER = dat1 >> 7;		 
//		dat1 <<= 1;
//
//		SRCLK = 0;			
//		_nop_();
//		_nop_();
//		SRCLK = 1;	
//	}
//
//	for(a=0;a<8;a++)		
//	{
//		SER = dat2 >> 7;		
//		dat2 <<= 1;
//
//		SRCLK = 0;			
//		_nop_();
//		_nop_();
//		SRCLK = 1;	
//	}
//
//	for(a=0;a<8;a++)		
//	{
//		SER = dat3 >> 7;		 
//		dat3 <<= 1;
//
//		SRCLK = 0;			 
//		_nop_();
//		_nop_();
//		SRCLK = 1;	
//	}
//
//	for(a=0;a<8;a++)	
//	{
//		SER = dat4 >> 7;	
//		dat4 <<= 1;
//
//		SRCLK = 0;		
//		_nop_();
//		_nop_();
//		SRCLK = 1;	
//	}
//
//	RCLK = 0;
//	_nop_();
//	_nop_();
//	RCLK = 1;
//}
//
//void main()
//{	
//	u8 i;
//	ledduan1[1] = ledduan1[1] | wei[1];
//	ledduan1[1] = ledduan1[1] | wei[2];
//	ledduan1[1] = ledduan1[1] | wei[3];
//	while(1)
//	{	 
//		for(i=0;i<16;i++)
//		{
//			Hc595SendByte(~ledwei[i+16],~ledwei[i],ledduan1[16+i],ledduan1[i]);
//		}
//		cnt++;
//		if(cnt == 100)
//		{
//			cnt = 0;
//			change1();
//			ledduan1[shi[0]] |= wei[shi[1]];
//			ledduan1[zhong[0]] &= ~wei[zhong[1]];
//			change2();
//		}		
//	}		
//}