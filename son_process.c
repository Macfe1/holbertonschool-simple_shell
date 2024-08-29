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
 * son_process - to create the son process with the fork
 *
 * @line_buffer: is what we received from the user
 *
 * Return: void
 */
int son_process(char *line_buffer)
{
	char **array = NULL;
	int words_count = 0, words_free = 0;
	char *token = NULL, *tmp_line_buffer = strdup(line_buffer);
	pid_t son_pid;

	if (error_tmp_dup(tmp_line_buffer))
		return(-1);
	array = (char **) malloc(MAX_WORDS * sizeof(char *));
	if (array == NULL)
	{
		malloc_error(tmp_line_buffer, array);
		perror("error in memory allocation");
		return(-1);
	}
	token = strtok(tmp_line_buffer, "\n ");
	while (token != NULL)
	{
		array[words_count] = strdup(token);
		if (array[words_count] == NULL)
		{
			perror("error in the strdup");
			malloc_error(tmp_line_buffer, array);
			return (-1);
		}
		token = strtok(NULL, "\n ");
		words_count++;
	}
	array[words_count] = NULL;
	
	if (array[0] == NULL)
		return(-1);

	son_pid = fork();
	if (son_pid == -1)
	{
		perror("error in the fork");
		free(tmp_line_buffer);
		for (;words_free < words_count; words_free++)
				free(array[words_free]);
		free(array);
		free(line_buffer);
		return (1);
	}
	if (son_pid == 0)
	{
		execvp_function(array, tmp_line_buffer);
		exit(1);
	}
	free(tmp_line_buffer);
	for (;words_free < words_count; words_free++)
		free(array[words_free]);
	free(array);
	return (1);
}
