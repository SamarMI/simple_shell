#include "shell.h"

/**
 * *_memset - function fills the first n bytes of the memory area with cons b.
 * @s: pointer to area of memory.
 * @b: constant byte.
 * @n: numbers of bytes will be filled.
 * Return: poiner to area of memory after filled.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);

}

/**
 * ffree - frees a string of strings
 * @p_to_ptr: string of strings
 */
void ffree(char **p_to_ptr)
{
	char **ptr =   p_to_ptr;

	if (!p_to_ptr)
		return;

	while (p_to_ptr)
		free(p_to_ptr++);
	free(ptr);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to new block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (old_size == new_size)
		return (ptr);
	if (!new_size)
		return (free(ptr), NULL);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];

	free(ptr);

	return (p);

}
