#include<stdio.h>
#define SUCCESS 0

int main()
{
    int n;

    printf("\n### Pattern printing : Invert numbered pyramid . ###\n\n");
    printf("Enter the value of n : ");
    if (scanf("%d", &n))
    {
        for (int i = n; i >= 1; i--)
        {
            for (int j = i; j <= n; j++)
            {
                printf(" ");
            }
            
            for (int j = 1; j <= i; j++)
            {
                printf("%d ", j);
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

### Pattern printing : Invert numbered pyramid . ###

Enter the value of n : 10
 1 2 3 4 5 6 7 8 9 10
  1 2 3 4 5 6 7 8 9
   1 2 3 4 5 6 7 8
    1 2 3 4 5 6 7
     1 2 3 4 5 6
      1 2 3 4 5
       1 2 3 4
        1 2 3
         1 2
          1

*/