#include "shell.h"

/**
 * helper - print help
 * @args: arguments
 *
 * Return: 1 on success, 0 failure
 */
int helper(char **args)
{
char *builtin_func_list[] = {
"cd",
"env",
"help",
"exit"
};
long unsigned int i = 0;
(void)(**args);

printf("\n---help collins_michelle_simple_shell---\n");
printf("Type command, then hit enter\n");
printf("Built-in commands:\n");
for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
{
printf("  -> %s\n", builtin_func_list[i]);
}
printf("Use the man command for more info.\n\n");
return (-1);
}