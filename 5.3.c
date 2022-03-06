#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int pid = fork();
	char commandName[32];

	if (pid == -1)
	{
		write(2, "Error while forking.\n", 22);
		exit(-1);
	}
	else if(pid > 0)
	{
		//write(1, commandName, 2);
		printf("%s\n", argv[1]);
	}
	else
	{
		if(execlp(argv[1], argv[1], 0) == -1)
		{
			write(2, "Cannot execute command.\n", 24);
			exit(-1);
		}
	}
}