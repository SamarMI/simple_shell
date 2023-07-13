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
	int l;

	if (ac > 0 && sizeof(av) > 0)
	{
	}
	l = isatty(STDIN_FILENO);
	if (l == 1)
		interactive(env);

	else
		non_interactive(env);

	return (0);

}*/
/**
 * 
*/
/*
void interactive(char **env)
{
	char *buffer, *token, *inpts[20];
	size_t size = 1000;
	int j = 0, k;

	while (1)
	{
		j = 0;
		buffer = malloc(sizeof(char) * size);
		if (buffer == NULL)
			return;
		getline(&buffer, &size, stdin);
		buffer[strcspn(buffer, "\n")] = 0;
		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			return;
		}
		k = check(buffer, j, inpts);
		token = strtok(buffer, " ");
		if (k == 0)
		{
			token = strtok(NULL, " ");
			j++;
		}
		while (token != NULL)
		{
			inpts[j] = malloc(sizeof(char) * strlen(token));
			if (inpts[j] == NULL)
			{
				freein(buffer, inpts, j, 1);
				return;
			}
			strcpy(inpts[j], token);
			j++;
			token = strtok(NULL, " ");
		}
		inpts[j] = NULL;
		execute(inpts, env);
		freein(buffer, inpts, j, 2);
	}
}
*
 * non_interactive - shell execute in non_interactive mode.
 * @env: env pointer for env variables.
 * 
*/
/*
void non_interactive(char **env)
{
	char *buffer, *token, *inpts[20];
	size_t size = 1000;
	int j = 0, k;

	{
		j = 0;
		buffer = malloc(sizeof(char) * size);
		if (buffer == NULL)
			return;
		getline(&buffer, &size, stdin);
		buffer[strcspn(buffer, "\n")] = 0;
		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			return;
		}
		k = check(buffer, j, inpts);
		token = strtok(buffer, " ");
		if (k == 0)
		{
			token = strtok(NULL, " ");
			j++;
		}
		while (token != NULL)
		{
			inpts[j] = malloc(sizeof(char) * strlen(token));
			if (inpts[j] == NULL)
			{
				freein(buffer, inpts, j, 1);
				return;
			}
			strcpy(inpts[j], token);
			j++;
			token = strtok(NULL, " ");
		}
		inpts[j] = NULL;
		execute(inpts, env);
		freein(buffer, inpts, j, 2);
	}
}
void execute(char **inputs, char **env)
{
	int status;
	pid_t pid;

	if (inputs[0] == NULL)
	{
		perror("");
		return;
	}
	else
	{
		if (access(inputs[0], F_OK) == 0)
		{
			pid = fork();
			wait(&status);
			if (pid == 0)
			{
				if (execve(inputs[0], inputs, env) == -1)
					perror("");
				return;
			}
		}
		else
		{
			perror("");
			return;
		}
	}
}

char *path_cm(char *cm)
{
	char *path, *path2, *token, *full_command;
	int cm_size, dir_size;
	struct stat buffer2;

	path = getenv("PATH");
	if (path)
	{
		path2 = strdup(path);
		cm_size = strlen(cm);
		token = strtok(path2, ":");
		while (token != NULL)
		{
			dir_size = strlen(token);
			full_command = malloc(cm_size + dir_size + 2);
			strcpy(full_command, token);
			strcat(full_command, "/");
			strcat(full_command, cm);
			strcat(full_command, "\0");
			if (stat(full_command, &buffer2) == 0)
			{
				free(path2);
				return (full_command);
			}
			else
			{
				free(full_command);
				token = strtok(NULL, ":");
			}
		}
		free(path2);
		if (stat(cm, &buffer2) == 0)
			return (cm);
		return (NULL);
	}
	return (NULL);
}*/
