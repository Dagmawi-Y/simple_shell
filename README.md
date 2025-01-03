# Simple Shell
![Unix Shell Image](shell.jpg)

This is a simple shell program designed to mimic the basic functionality of the `/bin/sh` shell.

## Description

The Simple Shell project is a command-line interpreter that allows users to interact with their operating system. It provides a simple interface for executing commands, managing processes, and handling input and output redirection.

## Features

- Executes commands entered by the user.
- Handles built-in commands such as `cd` and `exit`.
- Supports input and output redirection using `<` and `>` operators.
- Implements basic error handling and displays informative error messages.

## Requirements

- The project is written in C language and follows specific coding standards.
- It uses system calls and standard library functions for file and process management.
- Compilation is done using the GCC compiler with specific flags.

## Usage

To compile the shell program, run the following command:

- gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

To run the shell, execute the compiled binary:

- ./hsh

## File Structure

- `main.c`: Contains the `main` function for the shell program.
- `helper_functions.c`: Contains the helper functions for the main program.
- `executor.c`: Contains the `execute_command` function to execute a command with its arguments.
- `free_args.c`: Contains the `free_args` function to free memory allocated for arguments.
- `shell.h`: Header file defining function prototypes and macros used in the project.
- `README.md`: This file provides an overview of the project.
- `AUTHORS`: Lists contributors to the project.
- Other source files and header files as needed.


## Contributors

- [Dagmawi](https://github.com/Dagmawi-Y)
