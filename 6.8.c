#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

/*
Да се напише програма на C, която получава като параметри от 
командния ред две команди (без параметри). Изпълнява първата. 
Ако тя е завършила успешно изпълнява втората. Ако не, 
завършва с код -1.
*/

int main(int argc, char* argv[])
{
	int pid = fork();
	int status = 0;

	if (pid == -1)
	{
		write(1, "Error while forking.\n", 22);
		exit(-1);
	}
	else if (pid > 0)
	{
		if(wait(&status) == -1)
		{
			//execlp(argv[2], argv[2], 0);
			write(1, "Error while executing command 2.\n", 33);
			exit(-1);
		}
		else
		{
			execlp(argv[2], argv[2], 0);
		}
	}
	else
	{
		if(execlp(argv[1], argv[1], 0) == -1)
		{
			write(1, "Error while executing command 1.\n", 33);
			exit(-1);
		}
	}
}