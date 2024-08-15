#include "shell.h"

/**
 *
 *
 *
 */
int main ()
{
	char *line_buffer = NULL, *array[];
	size_t len = 0;
	ssize_t n_letters_read;
	pid_t son_pid;
	int pid_status = 0;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		n_letters_read = getline(&line_buffer, &len, stdin);
		if (n_letters_read == -1)
		{
			if (feof(stdin))
			{
				printf('\n');
				free(line_buffer);
				exit(0);
			}
			perror("is in getline");
			free(line_buffer);
			exit(1);
		}

		if (line_buffer[n_letters_read - 1] == '\n')
			line_buffer[n_letters_read - 1] = '\0';

		if (line_buffer[0] == '\0')
			continue;

		son_pid = fork();
	
		if (son_pid == -1)
		{
			perror("error in the fork");
			free(line_buffer);
			exit(1);
		}
	
		if (son_pid == 0)
		{
			array[0] = line_buffer;
			array[1] = NULL;
			execv(line_buffer, array);
		}

		if (execv == -1)
		{
			perror("execv error");
			exit(1);
		}

		if (son_pid > 0)
		{
			wait(&pid_status);
		}
	}

	free(line_buffer);
	return (0);
}
