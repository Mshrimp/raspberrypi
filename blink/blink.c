#include <stdio.h>
#include <bcm2835.h>

#define PIN 26

int main(int argc, char *argv[])
{
	int i = 0;

	if (!bcm2835_init())
		return 1;
	printf("bcm2835 init OK!\n");

	bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

	while (i < 4)
	{
		printf("i = %d\n", i);

		bcm2835_gpio_write(PIN, HIGH);
		printf("Set Pin High\n");
		bcm2835_delay(1000);

		bcm2835_gpio_write(PIN, LOW);
		printf("Set Pin Low\n");
		bcm2835_delay(1000);	

		i++;
	}
	bcm2835_close();

	return 0;
}
