#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char* argv[])
{
	int pid = fork();
	int fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	int r = 0, status = 0;
	char buff[32];

	if (pid == -1)
	{
		write(2, "Error while forking.\n", 22);
		exit(-1);
	}
	else if (pid > 0)
	{
		wait(&status);
		lseek(fd, 0, SEEK_SET);

		while (r = read(fd, buff, 1) > 0)
		{
			write(1, buff, 1);
			write(1, " ", 1);
		}
	}
	else
	{
		write(fd, "Hello\n", 6);
	}
}