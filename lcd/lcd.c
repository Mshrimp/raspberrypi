#include "lcd.h"


void write_date_or_cmd(unsigned char data_cmd)
{
	if (data_cmd == WRITE_CMD) {
		Set_Gpio_Output_Low(PIN_DATE_CMD);
	} else {
		Set_Gpio_Output_High(PIN_DATA_CMD);
	}
}


void write_byte(unsigned char byte)
{
	unsigned char i = 0;

	Set_Gpio_Output_Low(PIN_nCS);

	for (i = 0; i < 8; i++)
	{
		Set_Gpio_Output_Low(PIN_CLK);

		if (byte & (0x01<<(8-1))) {
			Set_Gpio_Output_High(PIN_DATA);
		} else {
			Set_Gpio_Output_Low(PIN_DATA);
		}

		Set_Gpio_Output_High(PIN_CLK);
		byte <<= 1;
	}
	
	Set_Gpio_Output_High(PIN_nCS);
}


void write_data(unsigned char data)
{
	write_data_or_cmd(WRITE_DATA);

	write_byte(data);
}


void write_cmd(unsigned char cmd)
{
	write_data_or_cmd(WRITE_CMD);

	write_byte(cmd);
}





