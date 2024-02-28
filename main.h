#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void execute_command(char *buffer, char **envp);
int read_command(char *buffer);

#endif /* MAIN_H */