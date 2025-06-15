#include<stdio.h>
#define SUCCESS 0

int main()
{
    int n;

    printf("\n### Pattern printing : Hollow square of star. ###\n\n");
    printf("Enter the value of n : ");
    if (scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%c ", ( (i == 0 || i == n- 1 || j == 0 || j == n-1) ? '*' : ' '));
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

    ### Pattern printing : Hollow square of star. ###

    Enter the value of n : 5
    * * * * * 
    *       *
    *       *
    *       * 
    * * * * *
    

*/