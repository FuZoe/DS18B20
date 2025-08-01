/*********************************************************************************
 * 文件名  ：main.c
 * 描述    ：通过stm32的spi1读取max6675的温度值，并通过uart1发送出来
 *          
 * 实验平台：STM32开发板
 * 库版本  ：ST3.0.0
 * 硬件连接： ------------------------------------
 *           |PA6-SPI1-MISO：MAX6675-SO          |
 *           |PA7-SPI1-MOSI：MAX6675-SI          |
 *           |PA5-SPI1-SCK ：MAX6675-SCK         |
 *           |PA4-SPI1-NSS ：MAX6675-CS          |
 *            ------------------------------------
**********************************************************************************/
#include "stm32f10x.h"
#include "oled.h"
#include "stdio.h"
#include "delay.h"
#include "ds18b20.h"

uint8_t ucbuf[17];
float temp_data=0.0;
float temp_data1=0.0;

void TEMP_Value_Conversion()
{
	temp_data=DS18B20_Get_Temp();
	temp_data1=temp_data/10.0;
	

	sprintf((char*)ucbuf,"%4.2f",temp_data1);
  OLED_ShowString(72,48,(uint8_t*)ucbuf,16,1);
  OLED_ShowChinese(0,48,0,16,1);
	OLED_ShowChinese(16,48,1,16,1);
	OLED_ShowChinese(32,48,2,16,1);
	OLED_ShowChinese(48,48,3,16,1);
	OLED_ShowChar(64,48,':',16,1);
	OLED_ShowChinese(112,48,4,16,1);
	  
}


/*
 * 函数名：main
 * 描述  ：主函数
 * 输入  ：无
 * 输出  ：无	
 */
main (void)
{
	/* 配置系统时钟为72M */
	SystemInit();
  

	DS18B20_Init();
	OLED_Init();
	OLED_ColorTurn(0);//0正常显示，1 反色显示
  OLED_DisplayTurn(0);//0正常显示 1 屏幕翻转显示
	OLED_ShowChinese(48,16,3,16,1);
	while(1)
	{
		OLED_Refresh();
		
		TEMP_Value_Conversion();
		Delay_ms(500);  
	}
}



