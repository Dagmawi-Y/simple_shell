#include "main.h"

/**
 * main - a Function that ...
 * Return: Description of the return value.
 */
int main(void)
{
	char *line;

	while (1)
	{
		printf("#cisfun$ ");
		line = read_line();
		if (line == NULL)
		{
			printf("\n");
			break;
		}
		execute_line(line);
		free(line);
	}

	return (0);
}

