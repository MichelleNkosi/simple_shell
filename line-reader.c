#include "shell.h"

/**
 * line_reader - read a line from stdin
 *
 * Return: pointer to line content
 */
char *line_reader(void)
{
char *line = NULL;
size_t bufsize = 0;

if (getline(&line, &bufsize, stdin) == -1)
{
if (feof(stdin))
{
free(line);
/* avoid memory leaks as per project info*/
exit(EXIT_SUCCESS);
}
else
{
free(line);
perror("error while reading lines");
exit(EXIT_FAILURE);
}
}
return (line);
}
