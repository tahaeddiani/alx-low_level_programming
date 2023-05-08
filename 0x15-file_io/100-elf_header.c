#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUF_SIZE 128

void print_hex(unsigned int value);
void print_elf_header(Elf64_Ehdr *header);

/**
* print_hex - Prints a hexadecimal value with leading "0x"
* @value: The value to print
*/
void print_hex(unsigned int value)
{
printf("0x%x", value);
}

/**
* print_elf_header - Displays the information contained in an ELF header
* @header: Pointer to the ELF header
*/
void print_elf_header(Elf64_Ehdr *header)
{
char magic[16];
memset(magic, 0, sizeof(magic));
memcpy(magic, header->e_ident, EI_NIDENT);

printf("ELF Header:\n");
printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
magic[0], magic[1], magic[2], magic[3], magic[4], magic[5], magic[6], magic[7],
magic[8], magic[9], magic[10], magic[11], magic[12], magic[13], magic[14], magic[15]);
printf("  Class:                             ");

switch (header->e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("Invalid class\n");
return;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("Unknown class\n");
return;
}

printf("  Data:                              ");

switch (header->e_ident[EI_DATA])
{
case ELFDATANONE:
printf("Invalid data encoding\n");
return;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("Unknown data encoding\n");
return;
}

printf("  Version:                           %d (current)\n", header->e_version);
printf("  OS/ABI:                            ");

switch (header->e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
default:
printf("<unknown: %d>\n", header->e_ident[EI_OSABI]);
break;
}

printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

printf("  Type:                              ");
switch (header->e_type)
{
case ET_NONE:
printf("No file type\n");
return;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %d>\n", header->e_type);
return;
}

printf("  Entry point address:               ");
print_hex(header->e_entry);
printf("\n");
}

/**
* main - Entry point
* @argc: Argument count
* @argv: Array of pointers to arguments
*
* Return: 0 on success, 98 on error
*/
int main(int argc, char **argv)
{
int fd;
Elf64_Ehdr header;
ssize_t n;

if (argc != 2)
{
fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
return 98;
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
perror("open");
return 98;
}

n = read(fd, &header, sizeof(header));
if (n < 0)
{
perror("read");
close(fd);
return 98;
