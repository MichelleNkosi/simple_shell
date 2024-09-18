#include "shell.h"

/**
 *interactive_option - command line interpreter
 *
 * Return: void
 */
void interactive_option(void)
{
char *line;
char **args;
int status = -1;

do {
printf("simple_prompt$ ");
line = line_reader();
args = line(line);
status = execute_args(args);
/* avoid memory leaks */
free(line);
free(args);
/* exit with status */
if (status >= 0)
{
exit(status);
}
} while (status == -1);
}