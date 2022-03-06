#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	open("fff", O_CREAT | O_TRUNC | O_RDWR, 0777);
	int fd1 = open("fff", O_RDONLY);
	int fd2 = open("fff", O_WRONLY);
	int fd3 = open("fff", O_RDWR);
	int r = 0;
	char* buff[32];

	//Every file descriptor has its own pointer

	if (fd1 == -1)
	{
		write(2, "Error in file descriptor 1\n", 27);
		exit(-1);
	}

	if (fd2 == -1)
	{
		write(2, "Error in file descriptor 2\n", 27);
		exit(-1);
	}

	if (fd3 == -1)
	{
		write(2, "Error in file descriptor 3\n", 27);
		exit(-1);
	}

	/*write(fd2, "Hello world\n", 12);

	read(fd3, buff, 6);
	write(1, buff, 6);

	read(fd1, buff, 5);
	write(1, buff, 5);

	write(fd3, "chil", 4);
	write(fd2, "!!!", 3);

	read(fd1, buff, 9);
	write(1, buff, 9);*/

	//----------------

	write(fd3, "Hello", 5);
	write(fd2, "worlds", 6);

	r = read(fd1, buff, 6);
	write(1, buff, r);

	close(fd2);
	write(fd3, "oops", 4);

	r = read(fd1, buff, 6);
	write(1, buff, r);

	close(fd1);
	close(fd3);
}