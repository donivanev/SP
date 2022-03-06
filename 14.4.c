#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int fd[2];
	//int fl1 = open(argv[1], O_RDONLY);
	//int fl2 = open(argv[2], O_WRONLY);

	pipe(fd);
	int pid = fork();

	if (pid == -1)
	{
		write(2, "Error while forking process.\n", 29);
		exit(-1);
	}
	else if (pid > 0)
	{
		close(0);
		dup(fd[0]);
		close(fd[0]);
		close(fd[1]);
		execlp("cat", "cat", argv[2], 0);
	}
	else
	{
		close(1);
		dup(fd[1]);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "pts", argv[1], 0);
	}
}