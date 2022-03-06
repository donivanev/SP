#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char* argv[])
{
	int pid = fork();
	int status = 0;

	if (pid == -1)
	{
		write(2, "Error while forking.\n", 22);
		exit(-1);
	}
	else if (pid > 0)
	{
		wait(&status);
		printf("Status = %d\n", status);
	}
	else
	{
		//execvp(argv[1], &argv[1])
		if (execvp(argv[1], argv + 1) == -1)
		{
			write(2, "Cannot execute command.\n", 24);
			exit(-1);
		}
	}
}