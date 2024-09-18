#include "shell.h"

/**
 *stream_reader - read a line from the stream
 *
 * Return: pointer to the read line
 */
char *stream_reader(void)
{
int bufsize = 1024;
int i = 0;
char *line = malloc(sizeof(char) * bufsize);
int character;

if (line == NULL)
{
fprintf(stderr, "error in read_stream");
exit(EXIT_FAILURE);
}
while (1)
{
character = getchar();
if (character == EOF)
{
free(line);
exit(EXIT_SUCCESS);
}
else if (character == '\n')
{
line[i] = '\0';
return (line);
}
else
{
line[i] = character;
}
i++;
if (i >= bufsize)
{
bufsize += bufsize;
line = realloc(line, bufsize);
if (line == NULL)
{
fprintf(stderr, "error in read_stream");
exit(EXIT_FAILURE);
}
}
}
}