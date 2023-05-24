#include "aya.h"

/**
 * get_cmd - gets cmd and creates a child process
 * Return: Success
 */

void get_cmd(void)
{
	char *text = NULL;
	size_t _buffs = 0;
	int _bufflen, child_pid, sT;

	_bufflen = getline(&text, &_buffs, stdin);
	if (_bufflen == -1)
	{
		free(text);
		exit(98);
	}
	if (_strlen(text) == 1)
	{
		free(text);
		return;
	}
	if (compare_chars(text, "exit\n", 6))
	{
		free(text);
		exit(0);
	}
	if (compare_chars(text, "env\n", 5))
	{
		_prints(environ);
		free(text);
		return;
	}
	else
	{
		child_pid = fork();
		if (child_pid < 0)
			perror("Error");
		else if (child_pid == 0)
			command_devide(text);
		else
		{
			wait(&sT);
			free(text);
		}
	}
}
