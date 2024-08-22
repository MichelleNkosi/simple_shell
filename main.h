#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int _atoi(char *str);
int calculate(int num1, int num2, char operator);
extern char **environ;

#endif /* MAIN_H */
