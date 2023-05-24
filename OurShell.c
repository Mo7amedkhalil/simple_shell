#include "aya.h"

/**
 * main - Entry point
 * @ac: args counter
 * @av: args array
 * Return: 0 (on success)
 */

int main(int ac, char **av)
{
	(void) ac;
	file_name = av[0];
	signal(SIGINT, ctrl);
	prompt();
	return (0);
}
