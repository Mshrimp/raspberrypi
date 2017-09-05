#include <stdio.h>
#include <stdlib.h>

#define TEMPPATH "/sys/class/thermal/thermal_zone0/temp"
#define MAX 20

int main(void)
{
    FILE * fp = NULL;
    float temp = 0;
    char buf[MAX];
    int ret = -1;

    fp = fopen(TEMPPATH, "r");
    if (fp == NULL)
    {
        printf("Failed to open file!\n");
        return -1;
    }  

    //if ((ret = read(fp, buf, MAX)) < 0)
    while (1)
    {
	if (ret = fread(buf, 1, MAX, fp) < 0)
	{
		printf("Failed to read file! ret = %d\n", ret);
		return -1;
	}

	temp = atoi(buf) / 1000.0;
	printf("Temp = %.2f\n", temp);
	sleep(2);
}

    if (fclose(fp) != 0)
        return -1;

    return 0;
}
