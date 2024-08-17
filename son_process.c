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
	char *array[2];
	pid_t son_pid;

	array[0] = line_buffer;
	array[1] = NULL;

	son_pid = fork();

	if (son_pid == -1)
	{
		perror("error in the fork");
		free(line_buffer);
		exit(1);
	}
	if (son_pid == 0)
	{
		printf("Entro a == 0\n");
		if (execv(line_buffer, array) == -1)
		{
			perror("execv error");
			free(line_buffer);
			exit(1);
		}
	}
}
