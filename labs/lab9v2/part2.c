#include <stdio.h>
#include <stdlib.h> // atoi, 'rand()'
#include <time.h>//required to use 'srand(time(NULL))'
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{

//char ch;
	int countString =0, countDouble=0,
		countInteger=0, countChar=0, intValue;

	double doubleValue;
	char charValue;
	char *string;


	int *intArray = (int*)malloc(100*sizeof(int));
	double *doubleArray = (double*)malloc(100*sizeof(double));
	char *charArray = (char*)malloc(100*sizeof(char));
	char *stringArray = (char*)malloc(100*sizeof(char));

	while(1)
	{
		printf("Enter your input: ");
		fgets(string, sizeof(string), stdin);

		//sstream ss;
		/*
		char *ep = NULL;
		const char *cstr = string.c_str();
		doubleValue = strtod (cstr, &ep);
		if (!ep || *ep || string.find('.') == std::string::npos) 
		{
			//ss>>intValue;
			
			if(string.fail()) 
			{
				//ss>>charValue;
				
				if(string.fail()) 
				{
					stringArray[countString++] = string;
				}
				else
				{
					charArray[countChar++] = charValue;
				}
				
			}
			else
			{
				//prints integer
				intArray[countInteger++] = intValue;
			}
		}
		else
		{
			doubleArray[countDouble++] = doubleValue;
		}
*/
		printf("\nString List: ");
		for(int i=0;i<countString;i++)
			printf("%s\n", stringArray[i]);
		

		printf("\nInteger List: ");
		for(int i=0;i<countInteger;i++)
			printf("%d\n", intArray[i] );
		

		printf("\nDouble List: ");
		for(int i=0;i<countDouble;i++)
			printf("%.2lf\n", doubleArray[i]);
			

		printf("\nCharacter List: ");
		for(int i=0;i<countChar;i++)
			printf("%s\n", charArray[i] );
		
	}
	
	//ch=fgetc(stdin);
	//strlwr(string);
	
	//putchar(tolower(string));
	
/*
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
	*/
	//printf("%s\n",charArray );
	// printf("%d # of occurences\n", count);
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