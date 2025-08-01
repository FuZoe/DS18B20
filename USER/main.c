/*********************************************************************************
 * �ļ���  ��main.c
 * ����    ��ͨ��stm32��spi1��ȡmax6675���¶�ֵ����ͨ��uart1���ͳ���
 *          
 * ʵ��ƽ̨��STM32������
 * ��汾  ��ST3.0.0
 * Ӳ�����ӣ� ------------------------------------
 *           |PA6-SPI1-MISO��MAX6675-SO          |
 *           |PA7-SPI1-MOSI��MAX6675-SI          |
 *           |PA5-SPI1-SCK ��MAX6675-SCK         |
 *           |PA4-SPI1-NSS ��MAX6675-CS          |
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
 * ��������main
 * ����  ��������
 * ����  ����
 * ���  ����	
 */
main (void)
{
	/* ����ϵͳʱ��Ϊ72M */
	SystemInit();
  

	DS18B20_Init();
	OLED_Init();
	OLED_ColorTurn(0);//0������ʾ��1 ��ɫ��ʾ
  OLED_DisplayTurn(0);//0������ʾ 1 ��Ļ��ת��ʾ
	OLED_ShowChinese(48,16,3,16,1);
	while(1)
	{
		OLED_Refresh();
		
		TEMP_Value_Conversion();
		Delay_ms(500);  
	}
}



