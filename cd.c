#include "shell.h"

/**
 * own_cd - changes the working dir
 * @args: target directory
 *
 * Return: 1 one success, 0 failure.
 */
int cd(char **args)
{
if (args[1] == NULL)
{
fprintf(stderr, "expected process to \"cd\"\n");
}
else
{
if (chdir(args[1]) != 0)
{
perror("error in cd.c: changing dir\n");
}
}
return (-1);
}