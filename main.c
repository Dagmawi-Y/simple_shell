#include "main.h"

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char *line;
	int status;

	while (1)
	{
		printf("#cisfun$ ");
		line = read_line();
		if (line == NULL)
		{
			printf("\n");
			break;
		}
		status = execute_line(line);
		free(line);
	}

	return (0);
}

