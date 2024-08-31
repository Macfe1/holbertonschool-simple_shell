#include "shell.h"


/**
 * get_env - 
 * if key es nulo retorna toda
 * si key vale algo, busca dentro de env la variable y retorna el value
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
	while (environ)
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
