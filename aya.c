#include <string.h>
#include "mohamed.h"

int main(void)
{
	char *str = "ls -1tr /tmp\n";
	const char *delim = "/n";
	char *token;

	token = strtok(str,delim);
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, delim);
	}
	return (0);
}
