#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

#define BUF_SIZE 1024

/**
* main - copies contents of one file to another
* @ac: the number of arguments passed to the program
* @av: an array of pointers to the arguments
*
* Return: 0 on success, or the corresponding error code on failure
*/
int main(int ac, char **av)
{
int fd_from, fd_to, n_read, n_written;
char buf[BUF_SIZE];

if (ac != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", av[0]);
return (EXIT_FAILURE);
}

fd_from = open(av[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
return (EXIT_FAILURE);
}

fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
close(fd_from);
return (EXIT_FAILURE);
}

while ((n_read = read(fd_from, buf, BUF_SIZE)) > 0)
{
n_written = write(fd_to, buf, n_read);
if (n_written != n_read || n_written == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
close(fd_from);
close(fd_to);
return (EXIT_FAILURE);
}
}

if (n_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
close(fd_from);
close(fd_to);
return (EXIT_FAILURE);
}

if (close(fd_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
close(fd_to);
return (EXIT_FAILURE);
}

if (close(fd_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
return (EXIT_FAILURE);
}

return (EXIT_SUCCESS);
}
