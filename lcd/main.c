
#include "lcd.h"

int main(int argc, char *argv[])
{
	if (bcm2835_init() == 0)
	{
		printf("bcm2835 init failed!\n");
		return -1;
	}



	bcm2835_close();

	return 0;
}

