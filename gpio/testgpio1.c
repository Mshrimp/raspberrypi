#include <wiringPi.h>
#include <stdio.h>

int main (void)
{
	//int i = 0;
	//int j = 0;
	int time = 200;
	int flag = 1;

	wiringPiSetup();
	pinMode (23, OUTPUT);
	pinMode (24, OUTPUT);
	pinMode (25, OUTPUT);
	pinMode (27, OUTPUT);
	pinMode (28, OUTPUT);
	pinMode (29, OUTPUT);

	while (1)
	{
		//for(i = 0; i < 6; i++)
		{
			digitalWrite(23, HIGH) ; delay (time) ;
                        digitalWrite(23,  LOW) ; delay (time) ;
			digitalWrite(24, HIGH) ; delay (time) ;
                        digitalWrite(24,  LOW) ; delay (time) ;
			digitalWrite(25, HIGH) ; delay (time) ;
                        digitalWrite(25,  LOW) ; delay (time) ;


			digitalWrite(27, HIGH) ; delay (time) ;
                        digitalWrite(27,  LOW) ; delay (time) ;
			digitalWrite(28, HIGH) ; delay (time) ;
                        digitalWrite(28,  LOW) ; delay (time) ;
	    		digitalWrite(29, HIGH) ; delay (time) ;
		    	digitalWrite(29,  LOW) ; delay (time) ;
		}

		printf("time = %d\n", time);
		time = flag ? time - 10 : time + 10;
		if ((time == 0) || (time == 200))
			flag = !flag;
	}

	return 0;
}
