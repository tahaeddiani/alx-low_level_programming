#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int validate_arguments(int argc, char **argv);
int copy_file(char *src_path, char *dst_path);

/**
* main - Entry point
* @argc: Argument count
* @argv: Array of pointers to arguments
*
* Return: Exit status code//Not mine
*/
int main(int argc, char **argv)
{
int status;

if (validate_arguments(argc, argv) != 0)
return 1;

status = copy_file(argv[1], argv[2]);

return status;
}

/**
* validate_arguments - Validates the number of arguments and files
* @argc: Argument count
* @argv: Array of pointers to arguments
*
* Return: 0 if valid, 1 otherwise
*/
int validate_arguments(int argc, char **argv)
{
int fd;
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
return 1;
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
return 1;
}
close(fd);

return 0;
}

/**
* copy_file - Copies the contents of one file into another
* @src_path: Path to source file
* @dst_path: Path to destination file
*
* Return: 0 on success or error code on failure
*/
int copy_file(char *src_path, char *dst_path)
{
int src_fd, dst_fd;
char buffer[BUFFER_SIZE];
ssize_t n_read, n_written;

src_fd = open(src_path, O_RDONLY);
if (src_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src_path);
return 98;
}

dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (dst_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dst_path);
close(src_fd);
return 99;
}

while ((n_read = read(src_fd, buffer, BUFFER_SIZE)) > 0)
{
n_written = write(dst_fd, buffer, n_read);
if (n_written != n_read || n_written == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dst_path);
close(src_fd);
close(dst_fd);
return 99;
}
}

if (n_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src_path);
close(src_fd);
close(dst_fd);
return 98;
}

if (close(src_fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_fd);
close(dst_fd);
return 100;
}

if (close(dst_fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dst_fd);
return 100;
}

return 0;
}
