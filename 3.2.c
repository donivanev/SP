#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int flrd = open(argv[1], O_RDONLY);
	int flwr = open(argv[1], O_WRONLY);
	int r = 0;
	char* buff[32];

	if (flrd == -1)
	{
		write(2, "Error in file descriptor 1\n", 27);
		exit(-1);
	}

	if (flwr == -1)
	{
		write(1, "Error in file descriptor 2\n", 27);
		exit(-1);
	}

	lseek(flwr, -3, SEEK_END);
	write(flwr, "wxyz", 4);

	lseek(flwr, 4, SEEK_SET);
	write(flwr, "12", 2);
	
	while(r = read(flrd, buff, 1) > 0)
	{
		write(1, buff, r);
	}

	close(flrd);
	close(flwr);
}