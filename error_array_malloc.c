#include "shell.h"

/**
 * malloc_error - handles the situation where malloc fails for the array
 *
 * @tmp_line_buffer: Temporal buffer
 * @array: array of arguments
 *
 * Return: void
 */
void malloc_error(char *tmp_line_buffer, char **array)
{
	int iterator_to_free = 0;

	free(tmp_line_buffer);
	perror("error in memory allocation");
	for (; array[iterator_to_free] != NULL; iterator_to_free++)
	{
		free(array[iterator_to_free]);
	}
	free(array);
}
