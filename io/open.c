#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main (void)
{
	int fd;

	fd = open ("test.txt", O_RDWR | O_CREAT, 00700);
	if (fd == -1)
	{
		perror ("Fail to open!");
		exit(1);
	}
	else
		printf ("Open file OK!\n");

	close(fd);

	return 0;
}
