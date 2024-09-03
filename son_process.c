#include "shell.h"

/**
 * error_tmp_dup - Manage the error when strdup fails
 *
 * @tmp_line_buffer: The temporal buffer that I tried to duplicate.
 *
 * Return: Returns 1 to indicate failure
 */
int error_tmp_dup(char *tmp_line_buffer)
{
	if (tmp_line_buffer == NULL)
	{
		perror("error in the strdup of line_buffer");
		return (1);
	}
	return (0);
}

/**
 * fork_process - to create the son process
 *
 * @line_buffer: where what teh user type in the shell
 * @tmp_line_buffer: a copy of the line buffer
 * @array: the array wiht the tokens
 *
 * Return:1 if success otherwise -1
 */
int fork_process(char *line_buffer, char *tmp_line_buffer, char **array)
{
	pid_t son_pid;

	son_pid = fork();

	if (son_pid == -1)
	{
		_freemalloc(tmp_line_buffer, array, 3);
		free(line_buffer);
		return (-1);
	}
	if (son_pid == 0)
	{
		execvp_function(array, tmp_line_buffer);
		return (1);
	}
	_freemalloc(tmp_line_buffer, array, 0);

	return (1);
}

/**
 * son_process - to create the son process with the fork
 *
 * @line_buffer: is what we received from the user
 *
 * Return: 1 if success
 */
int son_process(char *line_buffer)
{
	char **array = NULL;
	int words_count = 0;
	char *token = NULL, *tmp_line_buffer = strdup(line_buffer);

	if (error_tmp_dup(tmp_line_buffer))
		return (-1);
	array = (char **) malloc(MAX_WORDS * sizeof(char *));
	if (array == NULL)
	{
		_freemalloc(tmp_line_buffer, array, 1);
		return (-1);
	}
	token = strtok(tmp_line_buffer, "\n ");
	while (token != NULL)
	{
		array[words_count] = strdup(token);
		if (array[words_count] == NULL)
		{
			_freemalloc(tmp_line_buffer, array, 2);
			return (-1);
		}
		token = strtok(NULL, "\n ");
		words_count++;
	}
	array[words_count] = NULL;
	if (array[0] == NULL)
		return (-1);

	fork_process(line_buffer, tmp_line_buffer, array);

	return (1);
}
