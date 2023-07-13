#include "shell.h"

/**
 * _strcpy - to copy two strings.
 * @dest: destination string.
 * @src: src string.
 * Return: pointer to destination
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;

	return (dest);

}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}


/**
 * _strdup - to duplicate string.
 * @str:  string to duplicated.
 * Return: pointer to new string after duplicated.
*/
char *_strdup(const char *str)
{
	int length = 0;
	char *res;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	res = malloc(sizeof(char) * (length + 1));
	if (!res)
		return (NULL);
	for (length++; length--;)
		res[length] = *--str;
	return (res);
}

/**
 * _puts - to print string.
 * @str:  string to print.
*/
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
