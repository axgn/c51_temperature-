#ifndef __AT24C02_H__
#define __AT24C02_H__

/**
 * @brief at24c02写入字节
 * 
 * @param Addr 传入地址
 * @param Data 传入数据
 */
void AT24C02_Write(unsigned char Addr, unsigned char Data);

/**
 * @brief 读取某一地址的参数
 * 
 * @param Addr 
 * @return unsigned char 读取at24c02的值
 */
unsigned char AT24C02_Read(unsigned char Addr);

#endif