#include "shell.h"

/**
 *non_interactive_shell - command line interpreter
 *
 * Return: void
 */
void non_interactive_shell(void)
{
char *line;
char **args;
int status = -1;

do {
line = stream_reader();
args = split_line(line);
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
