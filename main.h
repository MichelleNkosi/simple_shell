#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

/*Prototypes for all functions*/
int _atoi(char *str);
int calculate(int num1, int num2, char operator);
/**
 *I promise this will make sense as we go along
 *void print_prompt(void);
 *int execute(char **argv);
*/
#endif /* MAIN_H */
