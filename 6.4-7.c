#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

	int pid = fork();

	if (pid == -1)
	{
		write(1, "Error while forking.\n", 22);
		exit(-1);
	}
	else if (pid > 0)
	{
		write(fd, "hello1\n", 7);
	}
	else
	{
		write(fd, "hello2\n", 7);
	}
}