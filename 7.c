#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

int main(int argc, char* argv[])
{
	int r = 0, status = 0;
	char buff[64];

	while(1)
	{
		write(1, "[CommandPrompt]$ ", 17);

		while(r = read(0, buff, 1) > 0)
		{
			//???
		}

		buff[r - 1] = '\0';

		if (strncmp(buff, "halt", 4) == 0)
		{
			exit(0);
		}

		int process = fork();

		if (process == -1)
		{
			write(1, "Error while forking process.\n", 29);
		}
		else if (process > 0)
		{
			wait(NULL);
		}
		else
		{
			if(execlp(buff, buff, 0) == -1)
			{
				write(1, "Cannot execute command\n", 23);
				exit(-1);
			}
		}
	}
}