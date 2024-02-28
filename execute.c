#include "main.h"

/**
 * execute_command - Execute a command
 * @argv: Arguments array
 * @env: Environment variables
 */
void execute_command(char **argv, char **env)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
        perror("Error");
    if (pid == 0)
    {
        if (execve(argv[0], argv, env) == -1)
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

/**
 * read_command - Read a command from input
 * Return: The command string
 */
char *read_command(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
        {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    }
    return (line);
}
