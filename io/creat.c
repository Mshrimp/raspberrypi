#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int fd;

	fd = creat("test.txt", 0700);
	if (fd == -1)
	{
		perror("Fail to creat file!");
		exit(1);
	}
	else
		printf("Creat file OK!\n");

	return 0;
}
