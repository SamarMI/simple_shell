#include "shell.h"

/**
 * StrToLower - change string to lowercase chars.
 * @str: string to convert.
 * Return: string after converted.
*/

char *StrToLower(char *str)
{
	char *pNew1 = str;
	char *pNew2 = str;

	if (str != NULL)
	{
		if (strlen(str) != 0)
		{
			while (*pNew1)
			{
				*pNew2 = _toLower(*pNew1);
				++pNew2;
				++pNew1;
			}
			*pNew2 = '\0';
			return (str);
		}
	}
	return ("");
}
/**
 * _toLower - change char to lower case.
 * @chr: char to change.
 * Return: char after chnged.
*/
int _toLower(int chr)
{
	return ((chr >= 'A' && chr <= 'Z') ? (chr + 32) : (chr));
}
