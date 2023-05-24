#include "aya.h"

/**
 * get_path - gets the path
 * @command: the cmd
 * Return: the full path, or NULL
 */

char *get_path(char *command)
{
	int i = 0;
	struct stat st;
	char **_pathcmd;

	_pathcmd = pathform(command);
	for (; _pathcmd[i] != NULL; i++)
	{
		if (stat(_pathcmd[i], &st) == 0)
			return (_pathcmd[i]);
	}
	return (NULL);
}

/**
 * pathform - gets possible of the cmd
 * @command: the cmd
 * Return: array of possible paths
 */


char **pathform(char *command)
{
	int i = 0;
	char *val, **arr = malloc(1024 * sizeof(char *));
	char *wd, *delim = ":";

	while (!compare_chars(environ[i], "PATH", 4))
		i++;
	val = erase_initials(environ[i], 5);
	wd = strtok(val, delim);
	i = 0;
	while (wd != NULL)
	{
		wd = concatenate(wd, "/");
		arr[i] = concatenate(wd, command);
		wd = strtok(NULL, delim);
		i++;
	}
	arr[i] = NULL;
	free(val);
	return (arr);
}
