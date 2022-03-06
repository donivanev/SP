#include <fcntl.h>  // open, close
#include <stdio.h>  //printf, scanf
#include <stdlib.h> // exit
#include <unistd.h> //read, write

int main(int argc, char* argv[])
{
	int fd = open(argv[1], O_RDONLY);
	int r = 0;
	char* buff[16];

	if(fd == -1)
	{
		write(2, "Cannot open file.\n", 18);
		exit(-1);
	}

	for (int i = 8; i >= 1; --i)
	{
		//lseek(fd, 0, 0);
		//lseek(fd, 3, 0);
		//lseek(fd, 3, SEEK_CUR);
		//lseek(fd, -3, SEEK_END);
		//i is decrementing, that's why the function 
		//will read 1 byte lesser
		r = read(fd, buff, i);

		//printf can't read exactly r bytes, that's why it
		//replaces the new letters onto the old ones 
		//printf("%s\n", buff);
		//but write can
		write(1, buff, r);
		write(1, "\n", 1);
	}

	close(fd);
}