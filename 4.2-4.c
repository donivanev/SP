#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	//int fd = open("file1", O_RDONLY | O_CREAT | O_EXCL, 0644);
	int fd = open(argv[1], O_RDWR | O_TRUNC | O_CREAT, 0644);

	if (fd == -1)
	{
		write(2, "Error in file descriptor\n", 25);
		exit(-1);
	}

	//close(1);
	//int fdOut = dup(fd);

	for (int i = 0; i < 10; ++i)
	{
		write(fRedirect, "EXAMPLE\n", 8);
		//printf("%s\n", "EXAMPLE");
	}

	close(fd);
	//close(fdOut);

	/*
	int fd;

	if ((fd = open("f1", O_CREAT|O_TRUNC|O_RDWR, 0666)) == -1) 
	{ 
		write(2, "Cannot open file abc \n", 24); 
		//exit(1);  
	}

	close(1);
	int k = dup(fd);

	for(int i = 0; i <= 15; ++i)
	   printf("i = %d\n", i);	


	int fd;
	char str[8] = "Hello";

	for(int i = 0; i <= 5; ++i)
	   printf("i = %d\n", i);

	int k = dup(1);

	write(1, "duplicated descriptor k = ", 
	 sizeof ("duplicated descriptor k = "));
	sprintf(str, "%d", k);

	write(1, str, strlen(str));
	write(1, "\n", 1);

	for (int i = 0; i <= 10; ++i)
	{
		sprintf(str, "i = %d\n", i);
		write(k, str, strlen(str));
	}*/
}