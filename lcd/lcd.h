
#include <stdio.h>
#include <bcm2835.h>


#define Set_Gpio_Dir_Output(pin)	bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_OUTP);
#define Set_Gpio_Dir_Input(pin)		bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_INPT);

#define Set_Gpio_Output_High(pin)	bcm2835_gpio_write(pin, HIGH)
#define Set_Gpio_Output_Low(pin)	bcm2835_gpio_write(pin, LOW)


#define PIN_CLK			RPI_V2_GPIO_P1_13
#define PIN_DATA		RPI_V2_GPIO_P1_11
#define PIN_DATA_CMD 	RPI_V2_GPIO_P1_07
#define PIN_nCS			RPI_V2_GPIO_P1_05
#define PIN_nRST		RPI_V2_GPIO_P1_03
#define PIN_BACK_LED	RPI_V2_GPIO_P1_15

#define WRITE_CMD	0
#define WRITE_DATA	1

#define LCD_X_MAX	84
#define LCD_Y_MAX	6


void write_date_or_cmd(unsigned char data_cmd);
void write_byte(unsigned char byte);
void lcd_write_data(unsigned char data);
void lcd_write_cmd(unsigned char cmd);
void lcd_gpio_config(void);
void lcd_clear(void);
void lcd_set_xy(unsigned char x, unsigned char y);
void lcd_write_char(unsigned char c);

