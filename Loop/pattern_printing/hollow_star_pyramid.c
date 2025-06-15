#include<stdio.h>
#define SUCCESS 0

int main()
{
    int n;

    printf("\n### Pattern printing : Hollow star pyramid . ###\n\n");
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
                printf("%c ", (i == 1 || i == n || j == i || j == 1 ) ? '*' : ' ');
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

### Pattern printing : Hollow star pyramid . ###

Enter the value of n : 10
          *
         * *
        *   *
       *     *
      *       *
     *         *
    *           *
   *             *
  *               *
 * * * * * * * * * *

*/