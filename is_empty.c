#include "shell.h"

/**
 * is_empty - to check if the buffer conatain only the SEPARATOR
 *
 * @line_buffer: Buffer where is save what the user provides
 *
 * Return: 1 if the buffer only have SEPARATOR otherwise 0
 */
int is_empty(char *line_buffer)
{
	while (*line_buffer)
	{
		if (!strchr(SEPARATOR, *line_buffer))
			return (0);
		line_buffer++;
	}
	return (1);
}
