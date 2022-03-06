#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int process1 = fork();
	int process2 = fork();
	int process3 = fork();

	if (process1 == -1)
	{
		write(1, "Error while forking.\n", 22);
		exit(-1);
	}
	else if (process1 > 0)
	{
		printf("pid = %d, ppid = %d\n", getpid(),getppid());
	}
	else
	{
		//int process2 = fork();
		printf("pid = %d, ppid = %d\n", getpid(),getppid());
	}
}