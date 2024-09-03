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
	int pid_status = 0, interactive_mode = isatty(STDIN_FILENO), status = 1,
	    gl_check = 0;

	while (status > 0)
	{
		if (interactive_mode == 1)
		{
			printf("#cisfun$ ");
			fflush(stdout);
		}
		errno = 0;
		n_letters_read = getline(&line_buffer, &len, stdin);
		gl_check = _getline_checker(n_letters_read, line_buffer,
				interactive_mode);
		if (gl_check == 1)
			break;
		if (gl_check == 2)
			continue;
		if (gl_check == 3)
			exit(1);
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
