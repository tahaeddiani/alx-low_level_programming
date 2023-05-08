#include "main.h"

/**
* create_file - creates a file with specified content
* @filename: the name of the file to create
* @text_content: the content to write to the file
*
* Return: 1 on success, -1 on failure //TahaED
*/
int create_file(const char *filename, char *text_content)
{
int fd, n_written = 0;
mode_t mode = S_IRUSR | S_IWUSR;

if (filename == NULL)
return (-1);

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, mode);
if (fd == -1)
return (-1);

if (text_content != NULL)
{
while (text_content[n_written] != '\0')
n_written++;

n_written = write(fd, text_content, n_written);
if (n_written == -1)
{
close(fd);
return (-1);
}
}

close(fd);

return (1);
}
