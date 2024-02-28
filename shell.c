#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * parse_line - a Function that ...
 * @line: Description of line.
 * Return: Description of the return value.
 */
char **parse_line(char *line);
/**
 * read_line - a Function that ...
 * Return: Description of the return value.
 */
char *read_line(void);

/**
 * execute_line - a Function that ...
 * @line: Description of line.
 * Return: Description of the return value.
 */
int execute_line(char *line)
{
	pid_t pid;
	int status;
	char **args;

	args = parse_line(line);
	if (args == NULL)
	{
		return (1);
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(args);
	return (1);
}

char **parse_line(char *line)
{
	const char *delimiters = " \t\r\n\a";
	char **tokens = malloc(sizeof(char *) * 64);
	char *token;
	int position = 0;

	if (tokens == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	token = strtok(line, delimiters);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		token = strtok(NULL, delimiters);
	}
	tokens[position] = NULL;

	return (tokens);
}

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	return (line);
}

