#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define TOK_DELIM " \t\r\n\a\""
extern char **environ;

/*PROTOTYPES*/
void interactive_option(void);
void non_interactive_shell(void);
char *line_reader(void);
char **split_line(char *line);
int execute_args(char **args);
int new_instances(char **args);
char *stream_reader(void);
int cd(char **args);
int exit_state(char **args);
int env(char **args);
int helper(char **args);

#endif
