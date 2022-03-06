#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int fl = open(argv[1], O_RDONLY);
	int fl2 = open(argv[2], O_CREAT | O_TRUNC | O_RDWR, 0644);
	int r = 0, i = 0;
	char buff[128];
	char helperBuff[128];

	if (fl == -1)
	{
		write(2, "Error in file descriptor 1\n", 27);
		exit(-1);
	}

	if (fl2 == -1)
	{
		write(2, "Error in file descriptor 2\n", 27);
		exit(-1);
	}

	while(r = read(fl, buff, 1))
	{
		helperBuff[i] = buff[0];
		i++;

		if (buff[0] == '$')
		{
			write(1, helperBuff, i);
			write(1, "\n", 1);
		}

		if (buff[0] == '\n')
		{
			helperBuff[0] = '\0'; 
			i = 0;
		}

		if (buff[0] >= '0' && buff[0] <= '9')
		{
			write(fl2, buff, 1);
			write(fl2, "\n", 1);
		}
	}

	execlp("wc", "wc", "-l", argv[2], 0);

	close(fl);
	close(fl2);
}