
#include <stdio.h>

int main ()
{
     int  mid; 

     for (int i= 1; i <= 10; i++)
     {
            printf(" ");
          mid = (2 * i) - 1;

          for (int j =1; j <=(10 - i); j++)
              printf(" ");  

          for (int j = i; j<= mid; j++)
         //   cout<<( j %10 ); 
				printf("%d",  j %10 );
          for (int j = (mid - 1); j >=i; j--)
        //     cout<<( j %10 );
			printf("%d",  j %10 );
            printf("\n");
     }
      return 0;

}