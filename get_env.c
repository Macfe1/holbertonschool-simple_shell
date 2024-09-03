#include "shell.h"


/**
 * get_env - prints the values of the environment variables.
 *
 * @key: the key to search for in the environment variables in order to get
 * its value.
 *
 * Description: If key is NULL, it will print all the environment variables.
 * Else if the key is not NULL, it will search for the variable in the
 * environment variable and returns its corresponding value.
 *
 * Return: The value of a given key in the environment variables. Else NULL.
 */
char *get_env(char *key)
{
	int i = 0;
	char *token;

	if (key == NULL)
	{
		while (environ[i] != NULL)
		{
			printf("%s\n", environ[i]);
			i++;
		}
		return (NULL);
	}
	if (environ)
	{
		while (environ[i] != NULL)
		{
			token = strtok(environ[i], "=");
			if (strcmp(token, key) == 0)
				return (strtok(NULL, "="));
			i++;
		}
	}
	return (NULL);
}
