#include "shell.h"

static char *token = NULL;
static int position = 0, len;
	
/**
 * _strtok - divide a string to substrings
 * @str: string to divide
 * @delim: delimeter used to divide
 * Return: pointer to divided string
 */

char *_strtok(char *str, const char *delim)
{
	int i , k = 0;
	
	if (str != NULL)
	{
		position = 0;
		token = NULL;
		len = strlen(str);
		for (i = 0; i < len; i++)
		{
			if (k == 1 && str[i] == delim[0])
			{
				str[i] = '\0';
				k = 1;
			}
			else if (k == 1 && str[i] != delim[0])
				k = 0 ;
			else if (str[i] == delim[0])
			{ 
				str[i] = '\0';
				k = 1;
			}
		}
		i = 0;
		while (str[i] == '\0')
			i++;
		token = str + i;
		if (len == 0 || i >= len)
		{
			token = NULL;
			len = 0;
			return (token);
		}
		len = len - i;
		return (token);
	}
	return (_strtok2());
}

/**
 * _strtok2 - used to give the next substring
 * Return: pointer to next substring
 */

char *_strtok2(void)
{
	unsigned int i , del = 0;

	if (token != NULL)
	{
		for (i = 0; position <= len; i++)
		{
			if (del == 1)
			{
				if (token[position] == '\0')
					del = 1;
				else
				{
					break;
				}
			}
			else if (token[position] == '\0')
				del = 1;
			(position)++;
		}
		if (position >= len)
		{
			token = NULL;
			position = 0;
			len = 0;
			return (NULL);
		}
		return (token + position);
	}
	return (token);
}
