#include "shell.h"

/**
 * main - Entry point for the simple shell.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("#cisfun$ ");
		line = read_line();
		args = split_line(line);
		status = execute_command(args);

		free(line);
		free_args(args);
	} while (status);

	return (0);
}

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
 * execute_command - Execute a command with its arguments.
 * @args: The array of command and arguments.
 *
 * Return: 1 if the shell should continue, 0 if the shell should exit.
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	} else
	{
		/* Parent process */
		wait(&status);
	}

	return (1);
}

/**
 * free_args - Free memory allocated for the array of arguments.
 * @args: The array of arguments to free.
 */
void free_args(char **args)
{
	free(args);
}

