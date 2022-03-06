#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

/*
Да се напише програма на С, която получава като параметър име 
на файл. Отваря подадения файл за писане (ако не съществува, 
го създава, в противен случай го занулява), създава 2 процеса 
и двата процеса пишат символния низ Hello във файла.
	•	чрез единствения дескриптор
	•	файла се отваря с 2 различни дескриптора.
	•	файла се отваря  с втори дескриптор, дублиращ първия
*/

int main(int argc, char* argv[])
{
	int pid = fork();
	int status = 0;
	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	//int fd2 = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	//int fdCopy = dup(fd);

	if (pid == -1)
	{
		write(2, "Error while forking.\n", 22);
		exit(-1);
	}
	else if (pid > 0)
	{
		wait(&status);
		write(fd, "Hello from parent\n", 18);
		//write(fd2, "Hello from parent\n", 18);
		//write(fdCopy, "Hello from parent\n", 18);
	}
	else
	{
		write(fd, "Hello from child\n", 18);
	}
}