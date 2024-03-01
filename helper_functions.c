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
/**
 * command_exists - Check if the command exists in the PATH.
 * @command: The command to check.
 *
 * Return: 1 if the command exists, 0 otherwise.
 */
int command_exists(const char *command)
{
	char *path = getenv("PATH");
	char *token, *path_copy;
	struct stat st;

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		char *full_path = malloc(strlen(token) + strlen(command) + 2);

		if (full_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		sprintf(full_path, "%s/%s", token, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			free(full_path);
			return (1);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (0);
}

