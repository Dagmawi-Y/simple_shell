#include "main.h"

/**
 * read_line - Read a line of input from stdin
 *
 * Return: Pointer to the read line
 */
char *read_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}

/**
 * execute_line - Execute a command line
 * @line: The command line to execute
 *
 * Return: Always 1
 */
int execute_line(char *line)
{
	pid_t pid;
	int status;

	line[strcspn(line, "\n")] = '\0'; /* Remove trailing newline */

	pid = fork();
	if (pid == 0) /* Child process */
	{
		if (execve(line, NULL, NULL) == -1)
		{
			perror(line);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) /* Error forking */
	{
		perror("fork");
	}
	else /* Parent process */
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

