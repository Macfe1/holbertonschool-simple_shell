#include "shell.h"

/**
 * main - entry point of the shell
 *
 * Return: 0 if success
 */
int main(void)
{
	char *line_buffer = NULL;
	size_t len = 0;
	ssize_t n_letters_read;
	int pid_status = 0;
	int interactive_mode = isatty(STDIN_FILENO), status = 1;

	while (status > 0)
	{
		if (interactive_mode == 1)
		{
			printf("#cisfun$ ");
			fflush(stdout);
		}
		errno = 0;
		n_letters_read = getline(&line_buffer, &len, stdin);
		if (n_letters_read == 0)
			break;
		if (n_letters_read == -1)
		{
			if (errno == 0)
			{
				if (interactive_mode)
					printf("\n");
				free(line_buffer);
				exit(0);
			}
			perror("error in getline");
			free(line_buffer);
			exit(1);
		}
		if (line_buffer[n_letters_read - 1] == '\n')
			line_buffer[n_letters_read - 1] = '\0';

		if (line_buffer[0] == '\0')
			continue;
		
		if (is_empty(line_buffer))
			continue;

		status = son_process(line_buffer);
		if (wait(&pid_status) == -1)
		{
			free(line_buffer);
			perror("Error in wait in the father process");
			exit(1);
		}
		
	}	
	free(line_buffer);
	return (0);
}
