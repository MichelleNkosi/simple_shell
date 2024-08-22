#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
