#include<stdio.h>
#define SUCCESS 0

int main()
{
    int n = 0;

    printf("\n\t### Print values from 1 to n. ###\n\n");
    printf("Enter the value of n : ");
    if (scanf("%d", &n))
    {
        if(n < 1)
        {
            printf("Please enter a value greater than 0.\n");
            printf("Entered value : %d.\n", n);
        }
        else
        {
            printf("Printing values from 1 to %d.\n\n", n);
            for (int i = 1; i <= n; i++)
            {
                printf("%d\n", i);
            }
        }
    }
    else
    {
        printf("Invalid input !\n");
    }

    return SUCCESS;
}