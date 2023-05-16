#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/*
 * main - simple shell
 * 
 * Return: 0 on success
 */

int main (int argc, char **argv)
{
	char *lineptr;
	size_t n = 0;
	ssize_t x = 0;
	char *cmd = NULL;

	(void)argc;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		x = getline(&lineptr, &n, stdin);
		
		if (x == -1)
		{
			return (1);
		}
		cmd = malloc(sizeof(char) *strlen(lineptr));
		
		if (cmd == NULL)
			return(1);
		strncat(cmd, lineptr, strlen(lineptr) - 1);
		if ((execve(cmd,argv,NULL) == -1))
				perror(cmd);
	}
	return(0);
}
