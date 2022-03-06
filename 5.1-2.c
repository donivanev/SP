#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int file = open(argv[1], O_RDONLY);

	if (file == -1)
	{
		write(2, "Cannot open file.\n", 16);
		exit(-1);
	}

	//execlp("gre", "gre", "int", argv[1], 0);
	execlp("grep", "grep", "int", argv[1], 0);

	close(file);

	return 0;
}