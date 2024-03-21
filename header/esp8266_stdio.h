#ifndef __ESP8266_STDIO_H__
#define __ESP8266_STDIO_H__

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

void UART_Init();
void UART_SendByte(uchar dat);
void ESP8266_SendCmd(uchar *pbuf);
void ESP8266_SendData(uchar *pbuf);
void ESP8266_ModeInit(void);

#endif