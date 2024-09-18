#include "shell.h"

/**
 * exit_state - process termination
 * @args: empty args
 *
 * Return: 0
 */
int exit_state(char **args)
{
/*status */
if (args[1])
{
return (atoi(args[1]));
}
/*success */
else
{
return (0);
}
}
