#include <stdio.h>
#include <stdlib.h> // atoi, 'rand()'
#include <time.h>//required to use 'srand(time(NULL))'


int main()
{
	char string[100];

	FILE *pFile;

	int count = 0;
	char *p;
	char character;

	pFile = fopen("myfile.txt", "r");
	if(pFile==NULL)
	{
		perror("Error opening file.");

	}
	else
	{
		if(fgets(string, sizeof(string), pFile) != NULL)
		{
			character = puts(string);

			for(p = string; *p; p++)
			{
				if(*p == character)
					count++;
			}
			printf("%u# of occurences\n", count);
		}
		fclose(pFile);
	}

	return 0;
}
/*
argv[0][4]
int main(int argc, char *argv[])
{
	printf("%d\n",argc );
}
./run s
argc = 2
argv[0]= "./run"
argv[1]= "s"
argv[1][0]='s'
*/