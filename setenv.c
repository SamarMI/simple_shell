#include "shell.h"

/**
 * set_env - set a new environment variable
 * @var: the new variable
 * @value: value to set
 */

void set_env(char *var, char *value)
{
	unsigned int i, size;
	char **arr;

	for (i = 0; environ[i] != NULL; i++)
	{
	}
	size = i + 1;
	if (getenv(var) == NULL)
	{
		arr = malloc(sizeof(char *) * (size + 1));
		if (arr == NULL)
		{
			perror("");
			return;
		}
		for (i = 0; environ[i] != NULL; i++)
		{
			arr[i] = environ[i];
		}
		arr[size - 1] = malloc(sizeof(char) * (strlen(var) + strlen(value) + 1));
		if (arr[size - 1] == NULL)
		{
			perror("");
			free(arr);
			return;
		}
		arr[size - 1] = strcpy(arr[size - 1], var);
		strcat(arr[size - 1], "=");
		strcat(arr[size - 1], value);
		arr[size] = NULL;
		environ = arr;
	}
	else
	{
		set2(var, value, size);
	}
}

/**
 * set2 - change existing variable value
 * @var: variable to change
 * @value: new value
 * @size: number of elements in environ
 */

void set2(char *var, char *value, unsigned int size)
{
	unsigned int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < strlen(var); j++)
		{
			if (environ[i][j] != var[j])
				break;
			if (var[j + 1] == '\0' && environ[i][j + 1] == '=')
			{
				environ[i] = malloc(sizeof(char) * (strlen(var) + strlen(value) + 1));
				if (environ[i] == NULL)
				{
					perror("");
					return;
				}
				environ[i] = strcpy(environ[i], var);
				strcat(environ[i], "=");
				strcat(environ[i], value);
				return;
			}
		}
	}
}

/**
 * unset_env - unset environment variable
 * @var: variable name
 */

void unset_env(char *var)
{
	unsigned int i, j, size, k = 0;
	char **arr;
	
	for (i = 0; environ[i] != NULL; i++)
        {
        }
	size = i + 1;
	arr = malloc(sizeof(char *) * (size - 1));
	if (arr == NULL || getenv(var) == NULL)
	{
		printf("Error\n");
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < strlen(var); j++)
		{
			if (environ[i][j] != var[j])
			{
				arr[k] = environ[i];
				k++;
				break;
			}
			if (var[j + 1] == '\0' && environ[i][j + 1] != '=')
			{
				arr[k] = environ[i];
				k++;
			}
		}
	}
	arr[k] = NULL;
	environ = arr;
}
