#include "shell.h"

/**
 * free_args - Free memory allocated for the array of arguments.
 * @args: The array of arguments to free.
 */
void free_args(char **args)
{
	free(args);
}

