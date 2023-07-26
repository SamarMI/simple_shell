#include "shell.h"

/**
 * _strlen - to det length of string.
 * @str: src string to get its length.
 * Return: length of string.
*/
int _strlen(char *str)
{
	int length = 0;

	if (!str)
		return (length);
	while (*str++)
	{
		length++;
	}

	return (length);

}


/**
 * _strcmp - to compare two strings.
 * @str1:  string 1 to compare.
 * @str2: string 2 to compare.
 * Return: negative if str1 < str2,
 *  positive if str1 > str2,
 *  zero if str1 == str2.
*/
int _strcmp(char *str1, char *str2)
{
	int i = 0;

	while (str1[i] == str2[i] && str1[i] && str2[i])
		i++;

	if (str1[i] == str2[i])
		return (0);

	return (str1 - str2);

}


/**
 * starts_with - to chick if str starts with pattern.
 * @pattern: pattern to check string strats with it;
 * @str: string which will checked.
 * Return: address of next char of pattern or NULL.
*/
char *starts_with(const char *pattern, const char *str)
{
	while (*str)
		if (*str++ != *pattern++)
			return (NULL);
	return ((char *)pattern);

}

/**
 * _strcat - to concatenates two strings.
 * @str1:  string 1 to concatenates.
 * @str2: string 2 to concatenates.
 * Return:pointer to str1.
*/
char *_strcat(char *str1, char *str2)
{
	char *res = str1;

	while (*str1)
		str1++;
	while (*str2)
		*str1++ = *str2++;
	*str1 = *str2;

	return (res);

}
