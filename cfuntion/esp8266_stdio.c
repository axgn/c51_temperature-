#include "stdio_basic.h"
#include<stdio.h>
#include "reg52.h"
#define RELOAD_COUNT 0xFA

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint unsigned int
#endif

sbit ESP8266_RST_Pin = P2 ^ 5;
sbit ESP8266_CH_PD_Pin = P2 ^ 6;


void ESP8266_SendCmd(uchar *pbuf)
{
    while (*pbuf != '\0') // 遇到空格跳出循环
    {
        UART_SendByte(*pbuf);
        delay_10us(5);
        pbuf++;
    }
    delay_10us(5);
    UART_SendByte('\r'); // 回车
    delay_10us(5);
    UART_SendByte('\n'); // 换行
    delay_ms(1000);
}

void ESP8266_SendData(uchar *pbuf)
{
    ESP8266_SendCmd("AT+CIPSEND=0,9");
    while (*pbuf != '\0') // 遇到空格跳出循环
    {
        UART_SendByte(*pbuf);
        delay_10us(5);
        pbuf++;
    }
    delay_10us(5);
    UART_SendByte('\n'); // 换行
    delay_ms(10);
}

// ESP8266-WIFI模块工作模式初始化
void ESP8266_ModeInit(void)
{
    ESP8266_RST_Pin = 1;
    ESP8266_CH_PD_Pin = 1;

    ESP8266_SendCmd("AT+CWMODE=3");                             // 设置路由器模式 1 staTIon模式 2 AP点 路由器模式 3 station+AP混合模式
    ESP8266_SendCmd("AT+CWSAP=\"168888\",\"prechin168\",11,0"); // 设置WIFI热点名及密码
    ESP8266_SendCmd("AT+CIPAP=\"192.168.4.2\"");                // 重新启动wifi模块
    ESP8266_SendCmd("AT+RST");                                  // 重新启动wifi模块
    ESP8266_SendCmd("AT+CIPMUX=1");                             // 开启多连接模式，允许多个各客户端接入
    ESP8266_SendCmd("AT+CIPSERVER=1,8080");                     // 启动TCP/IP 端口为8080 实现基于网络控制
}

void Uart() interrupt 4
{
    static u8 i = 0;
    if (RI)
    {
        RI = 0;
        RecBuf[i] = SBUF; //+IPD,0,1:F
        if (RecBuf[0] == '+')
            i++;
        else
            i = 0;
        if (i == 10)
        {
            i = 0;
            if (RecBuf[0] == '+' && RecBuf[1] == 'I' && RecBuf[2] == 'P' && RecBuf[3] == 'D')
            {
                switch (RecBuf[9])
                {
                case 'F':
                    led1 = 0;
                    break; // 点亮led1
                case 'B':
                    led1 = 1;
                    break; // 关闭led1
                case 'L':
                    relay = 0;
                    break; // 继电器
                case 'R':
                    relay = 1;
                    break; //
                }
            }
        }
    }
}