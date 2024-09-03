#include "shell.h"

/**
 * _freemalloc - frees memory allocation
 *
 * @tmp_line_buffer: Temporal buffer
 * @array: array of arguments
 * @err_message: For 1 it'll print error in malloc. For 2
 *
 * Return: void
 */
void _freemalloc(char *tmp_line_buffer, char **array, int err_message)
{
	int iterator_to_free = 0;

	if (err_message == 1)
		perror("Error in memory allocation");
	if (err_message == 2)
		perror("error in the strdup");
	if (err_message == 3)
		perror("error in the fork");
	
	free(tmp_line_buffer);
	for (; array[iterator_to_free] != NULL; iterator_to_free++)
	{
		free(array[iterator_to_free]);
	}
	free(array);
}
