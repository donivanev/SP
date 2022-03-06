#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	int fd = open(argv[1], O_RDONLY);
	int fdCopy = dup(fd);
	int r = 0;
	char* buff[128];

	if (fd == -1)
	{
		write(2, "Cannot open file.\n", 16);
		exit(-1);
	}

	//when copying the same descriptor 
	//it has the same position as the original
	r = read(fd, buff, 5);
	write(1, buff, r);

	r = read(fdCopy, buff, 10);
	write(1, buff, r);

	close(fd);

	r = read(fdCopy, buff, 10);
	write(1, buff, r);

	close(fdCopy);
}