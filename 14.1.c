#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char* argv[])
{
	int fl = open(argv[1], O_WRONLY);
	int pid1, pid2, status;

	int pid = fork();

	if (pid == -1)
	{
		write(2, "Error while forking process.\n", 29);
		exit(-1);
	}
	else if (pid > 0)
	{
		pid1 = wait(&status);

		if (fork() > 0)
		{
		    pid2 = wait(&status);

		    printf("%d\n", pid1);
			printf("%d\n", pid2);
			printf("%d\n", getpid());
		}
		else
		{
			if (execvp(argv[2], argv + 2) == -1)
			{
				write(2, "Cannot execute command 3.\n", 24);
				exit(-1);
			}
		}
	}
	else
	{
		if (fork() > 0)
		{
			wait(NULL);
			
			if (execlp("ls", "ls", "-l", ".", 0) == -1)
			{
				write(2, "Cannot execute command 2.\n", 24);
				exit(-1);
			}
		}
		else
		{
			if (execlp("cp", "cp", argv[1], "./f11", 0) == -1)
			{
				write(2, "Cannot execute command 1.\n", 24);
				exit(-1);
			}
		}
	}
}