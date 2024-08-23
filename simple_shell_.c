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
char **tokens = malloc(bufsize * sizeof(char *));
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
tokens = realloc(tokens, bufsize * sizeof(char *));
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
 * main - Entry point for the simple shell
 *
 * Return: 0 on success, 1 on error
 */
int main(void)
{
char *line = NULL;
char *argv[2];
size_t len = 0;
ssize_t nread;
int status;

while (1)
{
/* Display the prompt for user input */
printf("#cisfun$ ");
fflush(stdout);

/* Read the user input */
nread = getline(&line, &len, stdin);
if (nread == -1)
{
 /* Handle end of file condition (Ctrl+D) */
free(line);
break;
}

/* Remove the newline character from the input */
line[nread - 1] = '\0';

 /* Check if the input is empty */
if (strlen(line) == 0)
continue;


argv[0] = line;
argv[1] = NULL;

/* Execute the command */
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
