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
	int interactive_mode = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive_mode == 1)
		{
			printf("#cisfun$ ");
			fflush(stdout);
		}
		n_letters_read = getline(&line_buffer, &len, stdin);
		if (n_letters_read == -1)
		{
			if (feof(stdin))
			{
				if (interactive_mode == 1)
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
		son_process(line_buffer);
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
