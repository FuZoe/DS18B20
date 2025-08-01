引脚：

PB12 - DS18B20数据线

PB6 - OLED的SCL（时钟线）

PB7 - OLED的SDA（数据线）

PB2 - OLED的RES（复位线）



PS：有些OLED模块确实有RES引脚：某些OLED显示屏模块会额外提供一个RES（复位）引脚，用于硬件复位显示屏。

       如果您的OLED模块没有RES引脚：您可以：
       
		1.将PB2引脚悬空（不连接）
  
		2.或者将PB2连接到VCC（这样RES始终为高电平，相当于不进行硬件复位）
  


注：如果没有OLED显示屏，可以打开Keil调试模式，监测main.c中的变量temp_data1，这个变量代表温度，单位为摄氏度
