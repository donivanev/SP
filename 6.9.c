#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
Да се напише програма на C, която получава като командни 
параметри две команди (без параметри). Изпълнява ги 
едновременно и извежда на стандартния изход номера на процеса 
на първата завършила успешно. Ако нито една не завърши 
успешно извежда -1
*/

int main(int argc, char* argv[])
{
	int pid = fork();

	if (pid == -1)
	{
		write(1, "Error while forking.\n", 22);
		exit(-1);
	}
	else if (pid > 0)
	{
		printf("%s%d\n", "Pid = ", getpid());

		if (execlp(argv[2], argv[2], 0) == -1)
		{
			write(1, "Error while executing command 2.\n", 33);
			exit(-1);
		}
		else
		{
			printf("%d\n", -1);
		}
	}
	else
	{
		fork();

		if (execlp(argv[1], argv[1], 0) == -1)
		{
			write(1, "Error while executing command 2.\n", 33);
			exit(-1);
		}
	}
}