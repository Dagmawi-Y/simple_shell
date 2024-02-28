#include "main.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument array
 * @env: Environment variables
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv, char **env)
{
    char *line;
    char **args;

    (void)argc;
    (void)argv;

    do {
        printf(":) ");
        line = read_command();
        args = parse_line(line);
        execute_command(args, env);
        free(line);
        free(args);
    } while (1);

    return (0);
}
