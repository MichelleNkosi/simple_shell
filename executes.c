#include "shell.h"

/**
 * execute_args - map type of command
 * @args: command and its flags
 *
 * Return: 1 on sucess, 0 failure
 */
int execute_args(char **args)
{
char *builtin_func_list[] = {
"cd",
"env",
"help",
"exit"
};
int (*builtin_func[])(char **) = {
&cd,
&env,
&helper,
&exit_state
};
unsigned long int i = 0;

if (args[0] == NULL)
{
/* null command */
return (-1);
}
/* command is a builtin */
for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
{

if (strcmp(args[0], builtin_func_list[i]) == 0)
{
return ((*builtin_func[i])(args));
}
}
/* new process */
return (new_process(args));
}
