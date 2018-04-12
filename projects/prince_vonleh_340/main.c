
#include <stdio.h>

int main ()
{
     int  mid, count = 1; 
     

     for (int i= 1; i <= 8; i++)
     {
            printf(" ");
          mid = (2 * i) - 1;

          for (int j =1; j <=(10 - i); j++)
              printf(" ");  

          for (int j = i; j<= mid; j++)
     
				printf("%d",  j %10 );
          for (int j = (mid - 1); j >=i; j--)
			printf("%d",  j %10 );
            printf("\n");
     }
     
    /*
      while(count <=8)
      {
      	count++;
      	//printf("%dCOUNT1",count );
     	printf(" ");
     	mid = (2*count)-1;
     	//printf("%dMID",mid );
     	int a =1;
     	//printf("%dA1",a );
     	while(a <=(10-count))
     	{
     		a++;
     		printf(" ");
     		  
     		//printf("%dAinsideloop",a );
     	}
     	
     	int b=a;
     	//printf("%dAoutsideloop",a );
     	while(b <=mid)
     	{
     		b++; 
     		printf("%d",  b %10 );
     	}
     	
     	int c=(mid-1);
     	while(c >=count)
     	{
     		c--;  
     		printf("%d",  c %10 );
     		//printf(" ");
     		
     	}
     	printf("\n");
     	
     }
*/
      
      return 0;

}