#include "shell.h"
/**
 * check- check buffer and input
 * @buffer: buffer input from user.
 * @j: integer input
 * @inpts: pointer to input pointer.
 * Return: 1 if check sucsess.
*/


int check(char *buffer, int j, char **inpts)
{
	char *in, *token, buffer2[1000], full_command2[50];
	int k = 0;
	unsigned int i = 0;

	strcpy(buffer2, buffer);
	token = strtok(buffer2, " ");
	for (i = 0; i < strlen(buffer2); i++)
	{
		if (buffer2[i] == '/')
			{
				k = 1;
				break;
			}
	}
	if (k == 0)
	{
		in = path_cm(token, full_command2);
		inpts[j] = in;
	}
	return (k);
}
/*
void pre(void)
{
	char buffer[1000] , *token2;
        FILE *input;
        int i = 0;

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
}*/

/**
 * env_print - prints environment variables
 */

void env_print(void)
{
	int k;

	for(k = 0 ; environ[k] != NULL; k++)
	{
		printf("%s\n",environ[k]);
	}
}

/**
 * freein - free input
 * @buffer: buffer input from user.
 * @j: integer input
 * @inpts: pointer to input pointer.
 * @x: an integer to free buffer.
*/

void freein(char *buffer, char **inpts, int j, int x)
{
	if (x == 1)
	{
		free(buffer);
		while (j > 0)
		{
			free(inpts[j]);
			j--;
		}
	}
	else
	{
		free(buffer);
		while (j >= 0)
		{
			free(inpts[j]);
			j--;
		}
	}
}
