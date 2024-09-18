#include "shell.h"

/**
 * main - function that checks if our shell is called
 *
 * Return: 0 on success
 */
int main(void)
{
/* file descriptor is aligned with rules */
if (isatty(STDIN_FILENO) == 1)
{
interactive_option();
}
else
{
non_interactive_shell();
}
return (0);
}
