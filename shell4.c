#include "shell.h"


/**
 * main - shell program in interactive/noninteractive mode
 * @argc: number of command line arguments
 * @argv: command line arguments
 * @env: environment variable
 * RETURN: 0 on success
 */

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

/**
 * interactive - uses interactive mode
 * @env: environment variable
 */

void interactive(char **env)
{
	char *buffer ,*token, *inpts[20], *variable, *value;
	char arr[] = "setenv", arr2[] = "unsetenv";
	size_t size = 1000;
	int j = 0, k;
	unsigned int i = 0;

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
			env_print();
			continue;
		}
		while (arr[i] == buffer[i])
		{
			i++;
		}
		if (i == 6)
		{
			token = strtok(buffer, " ");
			variable = strtok(NULL, " ");
			value = token = strtok(NULL, " ");
			set_env(variable, value);
			continue;
		}
		i = 0;
		while (arr2[i] == buffer[i])
                {
                        i++;
                }
		if (i == 8)
                {
                        token = strtok(buffer, " ");
                        variable = strtok(NULL, " ");
                        unset_env(variable);
                        continue;
                }
		k = check(buffer, j, inpts);
		token = _strtok(buffer, " ");
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
		execute(inpts, env);
		free(buffer);
	}
}

/**
 * non_interactive - uses non interactive mode
 * @env: environment variables
 * Return: 0 on success
 */

int non_interactive(char **env)
{
	char *token, *inpts[20], *in[20], *variable, *value;
	char arr[] = "setenv", arr2[] = "unsetenv";
	int j = 0, k, i = 0, err = 0;
	char buffer[1000] , *token2;
        FILE *input;

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
        token2 = strtok(buffer, "\n");
        while (token2 != NULL)
        {
                in[i++] = token2;
                token2 = strtok(NULL, "\n");
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
			env_print();
			i++;
			continue;
		}
		while (arr[j] == in[i][j])
                {
                        j++;
                }
                if (j == 6)
                {
                        token = strtok(in[i], " ");
                        variable = strtok(NULL, " ");
                        value = token = strtok(NULL, " ");
                        set_env(variable, value);
                        continue;
                }
                j = 0;
                while (arr2[j] == in[i][j])
                {
                        j++;
                }
                if (j == 8)
                {
                        token = strtok(in[i], " ");
                        variable = strtok(NULL, " ");
                        unset_env(variable);
                        continue;
                }
		j = 0;
		k = check(in[i], j, inpts);
		token = strtok(in[i++], " ");
		if (k == 0)
		{
			token = strtok(NULL, " ");
			j++;
		}
		while (token != NULL)
		{
			inpts[j++] = token;
        		token = strtok(NULL, " ");
    		}
		inpts[j] = NULL;
		err = execute(inpts, env);
	}
	return (0);
}

/**
 * execute - executes a command of the shell
 * @inputs: command and arguments
 * @env: environment variables
 * Return: always 2
 */

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
		}
	}
	return (2);
}

/**
 * path_cm - gets the path of the command
 * @cm: command to use
 * @full_command2: full command with the path
 * Return: the full command with the path or command 
 * only if there is no path
 */

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
