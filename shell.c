#include "main.h"
#include <string.h>
#include <sys/wait.h>

/**
 * read_line - a Function that ...
 * Return: Description of the return value.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}

/**
 * execute_line - a Function that ...
 * @line: Description of line.
 * Return: Description of the return value.
 */
int execute_line(char *line)
{
	pid_t pid;
	int status;

	line[strcspn(line, "\n")] = '\0'; /* Remove trailing newline */

	pid = fork();
	if (pid == 0) /* Child process */
	{
		char *args[2];

		args[0] = line;
		args[1] = NULL;

		if (execve(line, args, NULL) == -1)
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

