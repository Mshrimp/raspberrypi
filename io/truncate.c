#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX 32
#define SIZE 50

int main (int argc, char *argv[])
{
	int fd;
	int len;
	int i;
	int rest;
	int buf[SIZE] = { 0 };
	int write_size = 0;
	int read_size = 0;
	
	if (argc != 4)
	{
		len = MAX;
		rest = 0;
	}
	else
	{
		len = atoi(argv[2]);
		rest = atoi(argv[3]);
	}
	printf("argc = %d\n", argc);
	for (i = 0; i < argc; i++)
		printf("argv[%d] = %s\n", i, (argv[i]));
	
	for (i = 0; i < SIZE; i++)
	{
		buf[i] = 2;
	}
	
	fd = open(argv[1], O_RDWR | O_APPEND | O_CREAT, 00777);
	
	if (fd == -1)
	{
		perror("Fail to open or creat file");
		exit(1);
	}
	
	write_size = write(fd, buf, SIZE);
	printf("%s has been written size : %d\n", argv[1], write_size);
/*		
	if (truncate("test.txt", MAX) == -1)
	{
		perror("Fail to truncate!\n");
		exit(1);
	}
	
	fd = 
	*/ 
	close(fd);
} 