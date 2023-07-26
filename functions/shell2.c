#include "shell.h"

/**
 * main - execute all shell fns
 * @ac: an argument.
 * @av: pointer to pointer for av.
 * @env: pointer to pointer for enviroment variables.
 *
 * Return: return 1 if sucsess.
 *
*/

/*
int main(int ac, char **av, char **env)
{
	char *buffer;
	char *path2 = getenv("PATH");
	char path[500];
	char *argv[20];
	size_t size = 100;
	pid_t pid;

	int j = 0, k = 0, sizeword = 0, status, l;
	unsigned int i = 0;
	char *token;

	token = strtok(path2,":");
	while (token != NULL)
	{
		strcpy(path, token);
		token = strtok(NULL, ":");
	}
	path[strlen(path)] = '/';
	if (ac > 0 && sizeof(av) > 0)
	{
	}
	l = isatty(STDIN_FILENO);
	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
		return (1);

	while(1)
	{
		j = 0;
		getline(&buffer, &size, stdin);
		buffer[strcspn(buffer, "\n")] = 0;

		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			return (0);
		}

		for (i = 0; i < strlen(buffer); i++)
		{
			if (buffer[i] == ' ' || buffer[i + 1] == '\0')
			{
				if (buffer[i + 1] == '\0')
					sizeword++;
				argv[j] = malloc( sizeword);
				if (argv[j] == NULL)
				{
					free(buffer);
					while(j >= 0)
					{
						free(argv[j]);
						j--;
					}
					return (1);
				}
				if (buffer[i + 1] == '\0')
					sizeword--;
				for (k = 0; k < sizeword; k++)
				{
					argv[j][k] = buffer[i - sizeword + k];
				}
				if (buffer[i + 1] == '\0')
					argv[j][k] = buffer[i - sizeword + k];
				if (buffer[i + 1] == '\0')
					sizeword++;
				argv[j][sizeword] = '\0';
				sizeword = 0;
				j++;
			}
			else
			{
				sizeword++;
			}
		}
		argv[j] = NULL;
		if (argv[0][0] != '/' && strlen(buffer) != 0)
		{
			strcat(path, argv[0]);
			free(argv[0]);
			argv[0] = malloc(sizeof(char) * strlen(path));
			if (argv[0] == NULL)
			{
				free(buffer);
				j--;
				while(j > 0)
				{
					free(argv[j]);
					j--;
				}
				return (1);
			}
			for (k = 0; k < (int)strlen(path); k++)
			{
				argv[0][k] = path[k];
			}
		}
		if (access(argv[0], F_OK) == 0)
		{
			pid = fork();
			wait(&status);
			if (pid == 0)
			{
				if (execve(argv[0], argv, env) == -1)
					perror("");
				return (0);
			}
		}
		else
		{
			perror("");
		}
		while(j >= 0)
		{
			free(argv[j]);
			j--;
		}
		for (i = 5; i < strlen(path); i++)
		{
			path[i] = 0;
		}
		if (l == 0)
			break;
	}
	free(buffer);
	return (0);
}
*/
