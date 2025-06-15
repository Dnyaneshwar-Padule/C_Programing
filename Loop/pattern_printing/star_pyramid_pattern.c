#include<stdio.h>
#define SUCCESS 0

int main()
{
    int n;

    printf("\n### Pattern printing : Star pyramid . ###\n\n");
    printf("Enter the value of n : ");
    if (scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                printf(" ");
            }
            
            for (int j = 1; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
        
    }
    else
    {
        printf("Invalid input !\n");
    }
    
    return SUCCESS;
}

/*
Output:

### Pattern printing : Star pyramid . ###

Enter the value of n : 10
          *
         * *
        * * *
       * * * *
      * * * * *
     * * * * * *
    * * * * * * *
   * * * * * * * *
  * * * * * * * * *
 * * * * * * * * * *

*/