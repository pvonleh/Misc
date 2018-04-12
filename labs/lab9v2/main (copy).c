#include <stdio.h>
#include <stdlib.h> // atoi, 'rand()'
#include <time.h>//required to use 'srand(time(NULL))'


int main()
{
	char string[100];

	FILE *pFile;

	pFile = fopen("myfile.txt", "r");
	if(pFile==NULL)
	{
		perror("Error opening file.");

	}
	else
	{
		if(fgets(string, 100, pFile) != NULL)
		{
			puts(string);
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