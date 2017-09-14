#include "lcd.h"



void write_data_or_cmd(unsigned char data_cmd)
{
	if (data_cmd == WRITE_CMD) {
		Set_Gpio_Output_Low(PIN_DATA_CMD);
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
		if (byte & 0x80) {
			Set_Gpio_Output_High(PIN_DATA);
		} else {
			Set_Gpio_Output_Low(PIN_DATA);
		}
		byte <<= 1;

		Set_Gpio_Output_Low(PIN_CLK);
		bcm2835_delay(10);
		Set_Gpio_Output_High(PIN_CLK);
	}
	
	Set_Gpio_Output_High(PIN_nCS);
}


void lcd_write_data(unsigned char data)
{
	printf("LCD write data!\n");

	write_data_or_cmd(WRITE_DATA);

	write_byte(data);
}


void lcd_write_cmd(unsigned char cmd)
{
	printf("LCD write cmd!\n");

	write_data_or_cmd(WRITE_CMD);

	write_byte(cmd);
}


void lcd_gpio_config(void)
{
	printf("LCD gpio config!\n");

	Set_Gpio_Dir_Output(PIN_CLK);
	Set_Gpio_Dir_Output(PIN_DATA);
	Set_Gpio_Dir_Output(PIN_DATA_CMD);
	Set_Gpio_Dir_Output(PIN_nCS);
	Set_Gpio_Dir_Output(PIN_nRST);
	Set_Gpio_Dir_Output(PIN_BACK_LED);

	Set_Gpio_Output_High(PIN_nCS);
	Set_Gpio_Output_High(PIN_nRST);
	Set_Gpio_Output_High(PIN_BACK_LED);

	Set_Gpio_Output_High(PIN_nCS);
	bcm2835_delay(2000);
	Set_Gpio_Output_Low(PIN_nCS);

	Set_Gpio_Output_High(PIN_nRST);
	bcm2835_delay(2000);
	Set_Gpio_Output_Low(PIN_nRST);

	Set_Gpio_Output_High(PIN_BACK_LED);
	bcm2835_delay(2000);
	Set_Gpio_Output_Low(PIN_BACK_LED);
}


int lcd_init(void)
{
	printf("LCD init!\n");

	lcd_gpio_config();
	

	Set_Gpio_Output_High(PIN_nCS);
	bcm2835_delay(100);
	Set_Gpio_Output_Low(PIN_nCS);

	lcd_write_cmd(0x21);
	lcd_write_cmd(0x07);
	lcd_write_cmd(0x13);
	lcd_write_cmd(128+65);

	lcd_write_cmd(0x20);
	lcd_write_cmd(0x0C);
	lcd_write_cmd(0x80);
	lcd_write_cmd(0x40);

	//clear();
	Set_Gpio_Output_High(PIN_BACK_LED);
	bcm2835_delay(2000);
	Set_Gpio_Output_Low(PIN_BACK_LED);
	

	return 0;
}


