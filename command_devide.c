#include "aya.h"

/**
 * command_devide - prepare for execve()
 * @text: the command
 * Return: Success
 */

void command_devide(char *text)
{
	char **cmd, *wd, *slice = NULL, *delim = " \t\n";
	int i = 0, exe_res, cmd_wd = 0;

	cmd = malloc(sizeof(char *) * (count_words(text) + 1));
	wd = strtok(text, delim);
	while (wd != NULL)
	{
		slice = malloc(_strlen(wd) + 1);
		_strcpy(slice, wd);
		cmd[i] = slice;
		cmd_wd++;
		i++;
		wd = strtok(NULL, delim);
	}
	cmd[i] = NULL;
	exe_res = exec(cmd);
	free_str(cmd, cmd_wd);
	free(cmd);
	if (exe_res == -1)
		exit(98);
}
