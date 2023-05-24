#include "aya.h"

/**
 * _strcpy - copy string
 * @dest: pointer to dest
 * @src: pointer to src
 * Return: copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int len = 0;

	while (src[len] != '\0')
		len++;
	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}
/**
 * count_words - counts the number of words in a string
 * @text: string variable
 * Return: integer number of words
 */
int count_words(char *text)
{
	int i, is_space, counter;

	if (text == NULL)
		return (0);

	is_space = 1;
	counter = 0;
	for (i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == ' ')
		{
			is_space = 1;
			continue;
		}
		else
		{
			if (is_space)
			{
				counter++;
				is_space = 0;
			}
		}
	}
	return (counter);
}

/**
 * _prints - prints every string on a single line
 * @strings: array of strings
 * Return: Success
 */
void _prints(char **strings)
{
	int i;

	for (i = 0; strings[i]; i++)
	{
		write_string(strings[i]);
		_putchar('\n');
	}
}

/**
 * free_strings - frees strings array
 * @strings: strings array
 * @n: num of char
 * Return: Success
 */

void free_str(char **strings, int n)
{
	int i = 0;

	while (i < n)
	{
		free(strings[i]);
		i++;
	}
}
