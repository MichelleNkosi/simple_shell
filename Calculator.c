#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point for the calculator
 * @argc: Argument count
 * @argv: Argument vector (array of arguments)
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
int num1, num2;
char operator;
int result;

/* Checks if the number of arguments is correct */
if (argc != 4)
{
printf("Usage: ./simple_calculator num1 operator num2\n");
return (1);
}

/* Converts arguments to integers */
num1 = _atoi(argv[1]);
num2 = _atoi(argv[3]);
operator = argv[2][0];

/* Perform the operation based on the operator */
result = calculate(num1, num2, operator);
if (result == -1)
return (1);

/* Prints the result */
printf("%d %c %d = %d\n", num1, operator, num2, result);

return (0);
}

/**
 * calculate - Performs the calculation based on the operator
 * @num1: First number
 * @num2: Second number
 * @operator: The operator (+, -, *, /)
 * Return: The result of the calculation,
 * or -1 if an error occurs
 */
int calculate(int num1, int num2, char operator)
{
int result;

switch (operator)
{
case '+':
result = num1 + num2;
break;
case '-':
result = num1 - num2;
break;
case '*':
result = num1 *num2;
break;
case '/':
if (num2 == 0)
{
printf("Error: Division by zero\n");
return (-1);
}
result = num1 / num2;
break;
default:
printf("Error: Unknown operator %c\n", operator);
return (-1);
}

return (result);
}

/**
 * _atoi - Converts a string to an integer
 * @str: The string to convert
 * Return: Integer
 */
int _atoi(char *str)
{
int num = 0;
int sign = 1;

/* Check for negative sign */
if (*str == '-')
{
sign = -1;
str++;
}

/* Convert each digit to an integer */
while (*str)
{
if (*str >= '0' && *str <= '9')
num = num * 10 + (*str - '0');
else
return (-1);
str++;
}

return (num *sign);
}

