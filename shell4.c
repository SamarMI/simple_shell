#include "shell.h"



int main(int argc, char **argv, char **env)
{
	int l;
	
	
	if (argc > 0 && sizeof(argv) > 0)
	{
	}
	l = isatty(STDIN_FILENO);
	if (l == 1)
		interactive(env);
	else
	{
		return (non_interactive(env));
	}
	return (0);
}

void interactive(char **env)
{
	char *buffer ,*token, *inpts[20];
	size_t size = 1000;
	int j = 0, k;

	while(1)
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
		if (strcmp(buffer, "env") == 0) 
		{
			for(k = 0 ; env[k] != NULL; k++)
			{
			printf("%s\n",env[k]);
			}
			continue;
		}
		k = check(buffer, j, inpts);
		token = _strtok(buffer, " ");
		if (k == 0)
		{
			token = strtok(NULL, " ");
			j++;
		}
		while (token != NULL)
		{
			inpts[j++] = token;
        		token = _strtok(NULL, " ");
    		}
		inpts[j] = NULL;
		execute(inpts, env);
		free(buffer);
	}
}

int non_interactive(char **env)
{
	char buffer[1000] ,*token, *token2, *in[20], *inpts[20];
	FILE *input;
	int j = 0, k, i = 0, err = 0;

	input = stdin;
	while (EOF != (buffer[i] = (unsigned char)fgetc(input)))
	{
		if (i > 900)
		{
			if (!(buffer[i] >= 33 && buffer[i] <= 122))
			{
			}
			else
				i++;
		}
		else
			i++;
	}
	buffer[i] = '\0';
	i = 0;
	token2 = _strtok(buffer, "\n");
	while (token2 != NULL)
	{
		in[i++] = token2;
		token2 = _strtok(NULL, "\n");
	}
	in[i] = NULL;
	i = 0;
	while (in[i] != NULL)
	{
		if (strcmp(in[i], "exit") == 0)
		{
			if (err != 0)
				exit(2);
			else
				return(0);
		}
		if (strcmp(in[i], "env") == 0)
		{
			for(k = 0 ; env[k] != NULL; k++)
			{
				printf("%s\n",env[k]);
			}
			i++;
			continue;
		}
		j = 0;
		k = check(in[i], j, inpts);
		token = _strtok(in[i++], " ");
		if (k == 0)
		{
			token = _strtok(NULL, " ");
			j++;
		}
		while (token != NULL)
		{
			inpts[j++] = token;
        		token = _strtok(NULL, " ");
    		}
		inpts[j] = NULL;
		err = execute(inpts, env);
	}
	return (0);
}
int execute(char **inputs, char **env)
{
	int status;
	pid_t pid;

	if (inputs[0] == NULL)
	{
		return (2);
	}
	else
	{
		/*
		if (access(inputs[0], F_OK) == 0)*/
		{
			pid = fork();
			wait(&status);
			if (pid == 0)
			{
			if (execve(inputs[0], inputs, env) == -1)
			{
					exit(2);
				}
			}
		}/*
		else
		{
			perror("");
			return;
		}*/
	}
	return (2);
}

char *path_cm(char *cm, char *full_command2)
{
	char *path, *path2, *token, *full_command;
	int cm_size, dir_size;
	struct stat buffer2;

	if (cm == NULL)
		return (NULL);
	path = getenv("PATH");
	if (path)
	{
		path2 = strdup(path);
		cm_size = strlen(cm);
		token = _strtok(path2, ":");
		while(token != NULL)
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
				strcpy(full_command2, full_command);
				free(full_command);
				return (full_command2);
			}
			else
			{
				free(full_command);
				token = _strtok(NULL, ":");
			}
		}
		free(path2);
		if (stat(cm, &buffer2) == 0)
			return (cm);
		return (cm);
	}
	return (cm);
}
