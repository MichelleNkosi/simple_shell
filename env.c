#include "main.h"
#include <stdio.h>

/**
* execute_env - Prints the environment variables
* @argv: The array of arguments (not used)
* Return: 1 to indicate the shell should continue running
*/
int execute_env(char **argv)
{
char **env = environ;

while (*env)
{
printf("%s\n", *env);
env++;
}

return 1;
}
