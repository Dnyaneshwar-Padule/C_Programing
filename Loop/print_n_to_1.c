#include<stdio.h>
#define SUCCESS 0

int main()
{
    int n = 0;

    printf("\n\t### Print values from n to 1. ###\n");
    printf("Enter the value of n : ");
    if (scanf("%d", &n))
    {
        if (n < 1)
        {
            printf("Please enter a value greater than 0.\n");
            printf("Entered value : %d.\n", n);
        }
        else
        {
            printf("Printing values from %d to 1.\n", n);
            for (; n >= 1; n--)
            {
                printf("%d\n", n);
            }   
        }
    }
    else
    {
        printf("Invalid input !\n");
    }    

    return SUCCESS;
}