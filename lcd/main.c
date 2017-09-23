
#include "lcd.h"

int main(int argc, char *argv[])
{
	if (bcm2835_init() == 0)
	{
		printf("bcm2835 init failed!\n");
		return -1;
	}
	printf("bcm2835 init OK!\n");

	lcd_init();

	lcd_set_xy(6, 3);
	lcd_write_char('A');

	printf("LCD init OK!\n");


	bcm2835_close();

	return 0;
}

