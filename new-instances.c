#include "shell.h"

/**
 * new_instance - create a new instance process
 * @args: array of strings that contains the command and its flags
 *
 * Return: 1 if success, 0 failure.
 */
int new_instances(char **args)
{
pid_t pid;
int status;

pid = fork();
if (pid ==  0)
{
/* arb process */
if (execvp(args[0], args) == -1)
{
perror("error in new instance");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
/* I want to try forking */
perror("error: forking");
}
else
{
/* core process */
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (-1);
}
