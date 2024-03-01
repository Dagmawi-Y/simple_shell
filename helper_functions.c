#include "shell.h"

/**
 * read_line - Read a line of input from stdin.
 *
 * Return: The line read from stdin.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}

/**
 * split_line - Split a line into tokens (words).
 * @line: The line to split.
 *
 * Return: An array of tokens.
 */
char **split_line(char *line)
{
	const char *delimiter = " \t\n";
	char **tokens = malloc(BUFFER_SIZE * sizeof(char *));
	char *token;
	int i = 0;

	if (!tokens)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, delimiter);
	while (token != NULL)
	{
		tokens[i++] = token;
		token = strtok(NULL, delimiter);
	}
	tokens[i] = NULL;
	return (tokens);
}

