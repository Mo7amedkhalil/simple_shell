#include "aya.h"	

/**
 * exec - executes the cmd
 * @command: cmd array
 * Return: 1 (on success), -1 (on failure)
 */

int exec(char **command)
{
	char *_path;

	if (access(command[0], F_OK) == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			write_string(file_name);
			return (-1);
		}
	}
	else
	{
		_path = get_path(command[0]);
		if (_path != NULL)
		{
			command[0] = _path;
			if (execve(command[0], command, environ) == -1)
			{
				write_string(file_name);
				return (-1);
			}
		}
		else
		{
			write_string(file_name);
			write_string(": No such file or directory\n");
			return (-1);
		}
	}
	return (1);
}
