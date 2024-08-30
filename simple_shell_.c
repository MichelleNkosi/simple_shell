#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * split_line - Splits a line into tokens (arguments)
 * @line: The line to be split
 * Return: An array of tokens (arguments)
 */
char **split_line(char *line)
{
int bufsize = 64, i = 0;
char **tokens = malloc(bufsize *sizeof(char *));
char *token;

if (!tokens)
{
perror("Allocation error");
exit(EXIT_FAILURE);
}

token = strtok(line, " \t\r\n\a");
while (token != NULL)
{
tokens[i] = token;
i++;

if (i >= bufsize)
{
bufsize += 64;
tokens = realloc(tokens, bufsize *sizeof(char *));
if (!tokens)
{
perror("Allocation error");
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, " \t\r\n\a");
}
tokens[i] = NULL;
return (tokens);
}

/**
 * read_input - Displays the prompt and reads the user input
 * @line: Pointer to the input line
 * @len: Pointer to the length of the input line
 * Return: The number of characters read
 */
ssize_t read_input(char **line, size_t *len)
{
printf("#cisfun$ ");
fflush(stdout);
return (getline(line, len, stdin));
}

/**
 * execute_command - Executes the given command
 * @argv: The array of arguments
 */
void execute_command(char **argv)
{
int status;

if (fork() == 0)
{
if (execve(argv[0], argv, environ) == -1)
{
perror("./shell");
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}
}

/**
 * main - Entry point for the simple shell
 * Return: 0 on success, 1 on error
 */
int main(void)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
char **argv;

while (1)
{

nread = read_input(&line, &len);
if (nread == -1)
{
free(line);
break;
}

/* Remove the newline character */
line[nread - 1] = '\0';

/* Check if the input is empty */
if (strlen(line) == 0)
continue;

/* Split the line into arguments */
argv = split_line(line);

/* Execute the command */
execute_command(argv);

/* Free the allocated memory */
free(argv);
}

return (0);
}

/**
*After line 79 We could Split the line into arguments
*split-line for commands that might eventually take arguments
*The other suggestion is just to 'avoid' memory leaks

argv = split_line(line);

Execute the command
if (fork() == 0)
{
if (execve(argv[0], argv, environ) == -1)
{
perror("./shell");
exit(EXIT_FAILURE);
}
}
else
{
wait(&status);
}
Free the allocated memory
free(argv);
}

free(line);
return (0);
}
 */
