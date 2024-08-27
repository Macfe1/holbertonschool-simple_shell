#include "shell.h"

/**
 * execvp_function - execute a comand provided by the user with execvp
 *
 * @array: array of arguments
 * @tmp_line_buffer: Temporal buffer
 *
 * Return: void
 */
void execvp_function(char **array, char *tmp_line_buffer)
{
	int word_counter_free = 0;

	if (execvp(array[0], array) == -1)
	{
		perror("execvp error");
		free(tmp_line_buffer);
		for (word_counter_free = 0;
				array[word_counter_free] != NULL; word_counter_free++)
		{
			free(array[word_counter_free]);
		}
		free(array);
		exit(1);
	}
}
