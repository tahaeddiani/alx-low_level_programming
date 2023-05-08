#include "main.h"

/**
* append_text_to_file - appends text to end of file
* @filename: the name of the file to modify
* @text_content: the content to append to the file
*
* Return: 1 on success, -1 on failure//TahaED
*/
int append_text_to_file(const char *filename, char *text_content)
{
int fd, n_written = 0;

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_APPEND);
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
