#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	char buff[10] = "I am here!";
	int f1 = open(argv[1], O_RDONLY);
	int f2 = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0644);

	if (f1 == -1)
	{
		write(2, "Cannot open file 1.\n", 20);
		exit(-1);
	}

	if (f2 == -1)
	{
		write(2, "Cannot open file 2.\n", 20);
		exit(-1);
	}

	close(0);
	int copyF1 = dup(f1);
	close(1);
	int copyF2 = dup(f2);

	read(copyF1, buff, 10);
	write(copyF1, "Receiving bytes ...\n", 20);

	close(f1);
	close(f2);

	/*
	int fd, i, nbytr, nbytw, filesize = 0;
	char buf[25], str[5];

	close(0);

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{ write(2, "Cannot open file for reading\n", 30); exit(1); }

	while (nbytr = read(0, buf, 25))
	{
	  nbytw = write(1, buf, nbytr);
	  if (nbytr = nbytw) filesize += nbytr;
	  else 	write(2, "I/O Error!\n", sizeof("I/O Error!\n"));
	}
	write(1, "\nSize of file --> ", 18);
	sprintf(str, "%d", filesize);
	write(1, str, strlen(str));
	write(1, " characters\n", 12); 
	*/
}