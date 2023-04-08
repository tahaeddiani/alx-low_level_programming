#include <stdio.h>
/**
 * main - main function where the main code is
 *
 *
 */
int main(int argc, char** argv){
	int loop;
	for (loop = 0; loop < argc; loop++)
{
		printf("%s",argv[loop]);
}
}
