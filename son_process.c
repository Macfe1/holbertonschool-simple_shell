#include "shell.h"

/**
 * son_process - to create the son process with the fork
 *
 * @line_buffer: is what we received from the user
 *
 * Return: void
 */
void son_process(char *line_buffer)
{
	char **array = NULL;
	char *token = NULL;
	int words_count = 0;
	char *tmp_line_buffer = strdup(line_buffer);
	pid_t son_pid;
	
	if (tmp_line_buffer == NULL)
	{
		perror("error in the strdup of line_buffer");
		return;
	}

	array = (char **) malloc (MAX_WORDS * sizeof(char *));
	if (array == NULL)
	{
		free(tmp_line_buffer);
		perror("error in memory allocation");
		return;
	}
	
	token = strtok(tmp_line_buffer, SEPARATOR);
	
	while (token != NULL)
	{
		array[words_count] = strdup(token);
		if (array[words_count] == NULL)
		{
			perror("error in the strdup");
			exit(1);
		}
		token = strtok(NULL, SEPARATOR);
		words_count++;
	}
	array[words_count] = NULL;

	son_pid = fork();

	if (son_pid == -1)
	{
		perror("error in the fork");
		free(line_buffer);
		free(array);
		exit(1);
	}
	if (son_pid == 0)
	{
		if (execvp(array[0], array) == -1)
		{
			perror("execvp error");
			free(tmp_line_buffer);
			free(array);
			exit(1);
		}
	}
	free(tmp_line_buffer);
	free(array);
}
