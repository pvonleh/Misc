#include <stdio.h>
#include <stdlib.h> // atoi, 'rand()'
#include <time.h>//required to use 'srand(time(NULL))'

/*
//Full Working Program
#include <stdio.h>
#include <stdlib.h>//required to use 'rand()'
#include <time.h>//required to use 'srand(time(NULL))'


int main()
{
srand(time(NULL));//required for "randomness"

 int r;
 r=rand()%6;//generate a number between 0 and 5
 printf("%i\n",r);

return 0;
}


int max_min(int max, int min)
{
	srand(time(NULL));//required for "randomness"

 int r;
 r=rand()%6;//generate a number between 0 and 5
 return printf("%i\n",r);
 //printf("%i\n",r);
}
*/
int max_min(int max, int min)
{
	srand(time(NULL));//required for "randomness"

 int num;
// r=rand()%6;//generate a number between 0 and 5
 for(int i=min; i <=max; i++)
	{
		if(num=rand()%8)
		{

		 return printf("%d\n", num );
		}
		else if(num=rand()%3+8)
		{
			return printf("%d\n", num );
		}
		else if (num=rand()%((max+1)-min)+min)
		{
			return printf("%d\n", num );
		}
		else
		{
			return printf("Enter max then min");
		}
	}
 //return printf("%i\n",r);
 //printf("%i\n",r);
}
int main()
{
	//int num1, num2;
	/*char num1[60];

	printf("Enter 2 integers max and min: ");
	fgets(num1, 60, stdin);

	int a = atoi(num1);
	//scanf("%d%d", &num1, &num2);
	//scanf("%d", &num2);
	printf("%d\n",a );
	*/
	int num1 = 1, num2 = 8;

	//num1 = 1;
	printf(max_min(&num1, &num2) );
/*
	printf("%d%d\n", num1, num2 );
int num;
	for(int i=num1; i <=num2; i++)
	{
		if(num= rand()%num2)
		{

		 printf("%d\n", num );
		}
		else if(num = rand()%3+num2)
		{
			printf("%d\n", num );
		}
		else if (num = rand()%((num2+1)-num1)+num1)
		{
			printf("%d\n", num );
		}
		else
		{
			printf("Enter max then min");
		}
	}


*/

	return 0;
}