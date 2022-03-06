#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc, char* argv[])
{
	int status = 0;

	for (int i = 1; i <= 3; ++i)
	{
		int pid = fork();

		if (pid == -1)
		{
			write(2, "Error while forking.\n", 22);
			exit(-1);
		}
		else if (pid > 0)
		{
			pid_t childPid = wait(&status);
			printf("Proccess ID %d = %d\nStatus %d = %d\n", 
				    i, childPid, i, status);
		}
		else 
		{
			execlp(argv[i], argv[i], 0);
		}
	}
}