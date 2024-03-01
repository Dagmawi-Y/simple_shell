#include "shell.h"

/**
 * execute_command - Execute a command with its arguments.
 * @args: The array of command and arguments.
 *
 * Return: 1 if the shell should continue,
 * 0 if the shell should exit.
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
		return (1);

	if (command_exists(args[0]) == 0)
	{
		printf("%s: command not found\n", args[0]);
		return (1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		wait(&status);
	}

	return (1);
}

