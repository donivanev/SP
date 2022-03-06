#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int fd = open(argv[2], O_RDONLY);
	int position = atoi(argv[1]);
	int r = 0;
	char buff[128];

	if (fd == -1)
	{
		write(2, "Error in file descriptor\n", 25);
		exit(-1);
	}

	while(r = read(fd, buff, 1) > 0)
	{
		if (buff[0] == '\n')
		{
			position--;
		}
		if (position <= 0)
		{
			write(1, buff, r);
		}
	}

	close(fd);
}