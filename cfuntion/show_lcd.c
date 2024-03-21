#include "reg52.h"
#include "intrins.h"
#include "delay.h"
#include <stdio.h>

#define uchar unsigned char
#define uint unsigned int

sbit LcdRs_P = P2 ^ 6;
sbit LcdRw_P = P2 ^ 5;
sbit LcdEn_P = P2 ^ 7;

void LcdWriteCmd(uchar cmd)
{
	LcdRs_P = 0;
	LcdRw_P = 0;
	LcdEn_P = 0;
	P0 = cmd;
	Delayms(10);
	LcdEn_P = 1;
	Delayms(10);
	LcdEn_P = 0;
}

void LcdWriteData(uchar dat)
{
	LcdRs_P = 1;
	LcdRw_P = 0;
	LcdEn_P = 0;
	P0 = dat;
	Delayms(10);
	LcdEn_P = 1;
	Delayms(10);
	LcdEn_P = 0;
}

void LcdGoToXY(uchar line, uchar column)
{
	if (line == 0)
		LcdWriteCmd(0x80 + column);
	if (line == 1)
		LcdWriteCmd(0x80 + 0x40 + column);
}

void LcdPrintStr(uchar *str)
{
	while (*str != '\0')
		LcdWriteData(*str++);
}

void LcdPrintInt(int num, int i)
{
	uchar str[10];
	uchar fomat[10];
	sprintf(fomat, "%%%dd", i);
	sprintf(str, fomat, num);
	LcdPrintStr(str);
}

void LcdPrintFloat(float num, int i)
{
	uchar str[10];
	uchar fomat[10];
	sprintf(fomat, "%%.%df", i);
	sprintf(str, fomat, num);
	LcdPrintStr(str);
}

void LcdInit()
{
	LcdWriteCmd(0x38);
	LcdWriteCmd(0x0C);
	LcdWriteCmd(0x06);
	LcdWriteCmd(0x01);
}

void LcdOn()
{
	LcdWriteCmd(0x0c);
}

void LcdOff()
{
	LcdWriteCmd(0x08);
}

void LcdShowInit()
{
	LcdGoToXY(0, 0);
	LcdPrintStr("   LCD Test  ");
	LcdGoToXY(1, 0);
	LcdPrintStr("ABCDEFGHIJKLMNOP");
}

void Lcdclear()
{
	LcdWriteCmd(0x01);
}

void Lcdmoveleft()
{
	LcdWriteCmd(0x18);
}

void Lcdmoveright()
{
	LcdWriteCmd(0x1c);
}