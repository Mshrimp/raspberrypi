#ifndef __LCD_H__
#define __LCD_H__


#include <bcm2835.h>


#define Set_Gpio_Dir_Output(pin)	bcm2835_gpio_fsel((pin), BCM2835_GPIO_FSEL_OUTP);

#define Set_Gpio_Output_High(pin)	bcm2835_gpio_write((pin), HIGH)
#define Set_Gpio_Output_Low(pin)	bcm2835_gpio_write((pin), LOW)


#define PIN_CLK			RPI_GPIO_P1_11
#define PIN_DATA		RPI_GPIO_P1_11
#define PIN_DATE_CMD 	RPI_GPIO_P1_11
#define PIN_nCS			RPI_GPIO_P1_11
#define PIN_nRST		RPI_GPIO_P1_11
#define PIN_BACK_LED	RPI_GPIO_P1_11

#define WRITE_CMD	0
#define WRITE_DATA	1



void write_date_or_cmd(unsigned char data_cmd);
void write_byte(unsigned char byte);
void write_data(unsigned char data);
void write_cmd(unsigned char cmd);


