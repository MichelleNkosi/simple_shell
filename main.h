#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/*Prototypes for all functions*/
int _atoi(char *str);
int calculate(int num1, int num2, char operator);
extern char **environ;
char **split_line(char *line);
ssize_t read_input(char **line, size_t *len);
void execute_command(char **argv);

/**
 *I promise this will make sense as we go along
 *void print_prompt(void);
 *int execute(char **argv);
*/

#endif /* MAIN_H */
