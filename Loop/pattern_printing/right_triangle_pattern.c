#include<stdio.h>
#define SUCCESS 0

int main()
{
    int n;

    printf("\n### Pattern printing : Right-angled traingle. ###\n\n");
    printf("Enter the value of n : ");
    if (scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
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

    ### Pattern printing : Right-angled traingle. ###

    Enter the value of n : 5
    * 
    * *
    * * *
    * * * *
    * * * * * 

*/