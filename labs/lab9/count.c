#include <stdio.h>
#include <stdlib.h> // atoi, 'rand()'
#include <time.h>//required to use 'srand(time(NULL))'
#include <ctype.h>


int main(int argc, char *argv[])
{
	char string[100];

//char ch;

	int count=0, upper=0;
	char check = argv[1][0];

	fgets(string, sizeof(string), stdin);
	//ch=fgetc(stdin);
	//strlwr(string);
	
	//putchar(tolower(string));
	

	for(int i =0; i< sizeof(string); i++)
	{
		//while(string[i] != '')
		//{
		if(string[i] >= 'A' && string[i] <= 'Z')
			upper++;
		//}
		if(check==string[i])
			count++;

	}

	printf("%d # of occurences\n", count);
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