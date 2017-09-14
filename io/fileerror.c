#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (void)
{
	int fd;

	fd = open ("no_file", O_RDONLY);
	if (fd == -1)
		perror("Fail to open!--Hello");
	else
		close(fd);

	fd = open("denied", O_WRONLY);
	if (fd == -1)
		perror("Fail to open!--Denied");
	else
		close(fd);

	return 0;
}
