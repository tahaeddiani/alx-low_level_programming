#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i, dr, y1;

		for(i=1; i<argc; i++)
		{
			y1 = atoi(argv[i]);
			dr += y1;	
		}
		printf("%i\n", dr);
	return 0;

}
