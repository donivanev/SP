#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char str[20];
	int fd = open(argv[1], O_RDWR | O_TRUNC | O_CREAT, 0644);

	if (fd == -1)
	{
		write(2, "Error in file descriptor\n", 25);
		exit(-1);
	}

	for (int i = 0; i < 10; ++i)
	{
		write(1, "EXAMPLE\n", 8);
	}

	int copyOut = dup(1);
	close(1);
	int fdOut = dup(fd);

	for (int i = 1; i <= 10; ++i)
	{
		sprintf(str, "%d\n", i);
	    write(1, str, strlen(str));
	}

	close(1);
	dup(copyOut);
	
	for (int i = 0; i < 10; ++i)
	{	
		//write(1, "HELLO\n", 6);
		printf("%s\n", "HELLO");
	}

	close(fd);
	close(copyOut);
	close(fdOut);
}