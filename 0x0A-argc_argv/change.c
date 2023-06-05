#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        int i;
	int cents, count;
	if(argc==2)
	{
	cents = atoi(argv[1]);
	}
	for(i=0; cents>0; i++)
	{
		if(cents >= 25)
		{
			cents -= 25;
			
		}
		else if(cents >= 10)
		{
			cents -= 10;
		}

		else if(cents >= 5)
                {
                        cents -= 5;
                }

		else if(cents >= 2)
                {
                        cents -= 2;
                }
		
		else if(cents == 1)
		{
			cents -= 1;
		}
		count++;
	}
		printf("%d\n", count);
		return 0;
}
