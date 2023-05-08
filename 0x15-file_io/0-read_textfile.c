#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * read_textfile - function that reads a text file & print it
 * @filename: pointer to const string
 * @letters: variable type size_t
 * Return: return 0 // TahaED
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
ssize_t n_read, n_written;
char *buf;

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buf = malloc(sizeof(char) * letters);
if (buf == NULL)
{
close(fd);
return (0);
}

n_read = read(fd, buf, letters);
if (n_read == -1)
{
free(buf);
close(fd);
return (0);
}

n_written = write(STDOUT_FILENO, buf, n_read);
free(buf);
close(fd);

if (n_written != n_read)
return (0);

return (n_read);
}
