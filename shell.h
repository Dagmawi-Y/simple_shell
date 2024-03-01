#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* Function prototypes */
char *read_line(void);
char **split_line(char *line);
int execute_command(char **args);
void free_args(char **args);

#endif /* SHELL_H */

