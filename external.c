#include "aya.h"

/**
 * erase_initials - erases first n chars
 * @str: pointer to a string
 * @n: num of chars to be removed
 * Return: modified string
 */

char *erase_initials(char *str, int n)
{
	int i, _len;
	char *modified;

	if (str == NULL)
		return (NULL);
	_len = _strlen(str);
	if (n <= 0 || n >= _len)
		return (str);
	modified = (char *)malloc((_len - n + 1) * sizeof(char));
	if (modified == NULL)
		return (NULL);
	for (i = n; i < _len; i++)
		modified[i - n] = str[i];
	modified[_len - n] = '\0';
	return (modified);
}

/**
 * ctrl - handles ctrl + c cmd
 * @i: gabage var
 * Return: Success
 */

void ctrl(int i)
{
	(void) i;
	write(1, "\n$ ", 3);
}
