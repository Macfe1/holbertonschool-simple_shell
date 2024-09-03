#include "shell.h"

/**
 * _getline_checker - function to call after a getline to check if everything
 * went well
 *
 * @gl_rvalue: the variable that holds the return value of a getline call
 * @gl_buffer: the buffer argument that you first passed to getline
 * @interactive_mode: interactive mode of the program
 *
 * Return: 0 if no need for any of the if conditions to execute.
 * 1 if a certain if statement calls for a break statement in the main
 * 2 if a certain if statement calls for a continue statement in the main
 * 3 if a certain if statement calls for a exit function in the main
 */
int _getline_checker(ssize_t gl_rvalue, char *gl_buffer, int interactive_mode)
{
	if (gl_rvalue == 0)
		return (1);
	if (gl_rvalue == -1)
	{
		if (errno == 0)
		{
			if (interactive_mode)
				printf("\n");
			free(gl_buffer);
			return (3);
		}
		perror("Error in getline");
		free(gl_buffer);
		return (3);
	}
	if (gl_buffer[gl_rvalue - 1] == '\n')
		gl_buffer[gl_rvalue - 1] = '\0';
	if (gl_buffer[0] == '\0')
		return (2);
	if (is_empty(gl_buffer))
		return (2);
	if ((strcmp(gl_buffer, "env") == 0) ||
			(strcmp(gl_buffer, "printenv") == 0))
	{
		get_env(NULL);
		return (2);
	}
	if ((strcmp(gl_buffer, "exit") == 0))
		return (1);

	return (0);
}
