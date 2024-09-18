#include "shell.h"

/**
 *line - split a string into multiple strings
 * @line: string to be splited
 *
 * Return: pointer that points to the new array
 */
char **line(char *line)
{
int bufsize = 64;
int i = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens)
{
fprintf(stderr, "error in split_line: tokens\n");
exit(EXIT_FAILURE);
}
token = strtok(line, TOK_DELIM);
while (token != NULL)
{

if (token[0] == '#')
{
break;
}
tokens[i] = token;
i++;
if (i >= bufsize)
{
bufsize += bufsize;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens)
{
fprintf(stderr, "reallocation issue");
exit(EXIT_FAILURE);
}
}
token = strtok(NULL, TOK_DELIM);
}
tokens[i] = NULL;
return (tokens);
}