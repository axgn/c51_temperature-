#ifndef __SHOW_LCD_H__
#define __SHOW_LCD_H__
// use p2.6 p2.5 p2.7 P0

void LcdGoToXY(unsigned char line, unsigned char column);
void LcdPrintStr(unsigned char *str);
void LcdPrintInt(unsigned int num, unsigned char i);
void LcdPrintFloat(float num, unsigned char i);
void LcdInit();
void LcdOn();
void LcdOff();
void LcdShowInit();
void Lcdclear();
void Lcdmoveleft();
void Lcdmoveright();

#endif