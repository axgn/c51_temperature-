#include <REGX52.H>
#include <string.h>

#define uchar unsigned char
#define uint unsigned int

sbit Data = P1 ^ 0; // 数据线
uchar rec_dat_h[5];
uchar rec_dat_t[4]; // 储存数据
void DHT11_delay_us(uchar n)
{
	while (--n)
		;
}
void DHT11_delay_ms(uint z)
{
	uint i, j;
	for (i = z; i > 0; i--)
		for (j = 110; j > 0; j--)
			;
}

/*
主机（单片机）发送起始信号：
1.主机先拉高data。
2.拉低data延迟18ms。
3.拉高data并延迟等待（通过此操作将单片机引脚设置为输入）。
*/
void DHT11_start()
{
	Data = 1;
	DHT11_delay_us(2);
	Data = 0;
	DHT11_delay_ms(25); // 拉低延时18ms以上
	Data = 1;
	DHT11_delay_us(30); // 拉高 延时 20~40us，取中间值 30us
}

/*------------------------------------------------
			  接收八位二进制
------------------------------------------------*/
uchar DHT11_rec_byte() // 接收一个字节
{
	unsigned char i, dat = 0;
	for (i = 0; i < 8; i++) // 从高到低依次接收8位数据
	{
		while (Data)
			; // 等待进入低电平
		while (!Data)
			;			   // 等待50us低电平过去
		DHT11_delay_us(8); // 延时60us，如果还为高则数据为1，否则为0
		dat <<= 1;		   // 移位（低位补零）使正确接收8位数据，数据为0时直接移位
		if (Data == 1)	   // 数据为1时，使dat加1来接收数据1
			dat += 1;
		while (Data)
			; // 等待数据线拉低
	}
	return dat;
}

/*------------------------------------------------
			  接收40bit数据（具体的温湿度）
1.主机先把data线拉高（io设置为输入）。
2.从机把data线拉低，主机读取data线电平，直到低电平结束（大约50us）
  从机拉高data线后，延迟40us左右（28~70us之间）主机再次读取data线电平，如果为低电平，则为“0”，如果为高电平，则为“1”。
3.继续重复上述1,2步骤累计40次。
------------------------------------------------*/
uchar T_H;
void DHT11_receive(uchar *rec_dat1_hum, uchar *rec_dat1_tem) // 接收40位的数据
{
	uchar R_H, R_L, T_L, RH, RL, TH, TL, revise;
	DHT11_start(); // 发送起始信号：
	if (Data == 0)
	{
		while (Data == 0)
			;				// 等待拉高
		DHT11_delay_us(40); // 拉高后延时80us

		R_H = DHT11_rec_byte();	   // 接收湿度高八位
		R_L = DHT11_rec_byte();	   // 接收湿度低八位
		T_H = DHT11_rec_byte();	   // 接收温度高八位
		T_L = DHT11_rec_byte();	   // 接收温度低八位
		revise = DHT11_rec_byte(); // 接收校正位

		DHT11_delay_us(25); // 结束

		if ((R_H + R_L + T_H + T_L) == revise) // 最后一字节为校验位，校验是否正确
		{
			RH = R_H;
			RL = R_L;
			TH = T_H;
			TL = T_L;
		}

		/*数据处理，转换为字符，方便显示*/
		// 湿度
		rec_dat_h[0] = '0' + (RH / 10);
		rec_dat_h[1] = '0' + (RH % 10);
		rec_dat_h[2] = '%';
		rec_dat_h[3] = ' ';

		// 温度
		rec_dat_t[4] = '0' + (TH / 10);
		rec_dat_t[5] = '0' + (TH % 10);
		rec_dat_t[6] = ' ';
	}
	strcpy(rec_dat1_hum, rec_dat_h);
	strcpy(rec_dat1_tem, rec_dat_t);
}
