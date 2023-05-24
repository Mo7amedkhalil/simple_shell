#include "aya.h"

/**
 * prompt - takes user's cmds
 * Return: Success
 */

void prompt(void)
{
	if (!isatty(0))
	{
		get_cmd();
		return;
	}
	while (1)
	{
		write_string("$ ");
		get_cmd();
	}
}
