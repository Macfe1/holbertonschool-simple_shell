#include "shell.h"

/**
 *
 *
 *
 */
int main ()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t letters_read;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		letters_read = getline(line, len, stdin);
		if (letters_read == -1)
			
	}


}
