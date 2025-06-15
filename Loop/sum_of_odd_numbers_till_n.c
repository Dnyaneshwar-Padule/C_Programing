#include<stdio.h>
#define SUCCESS 0

int main()
{
    int n = 0, sum = 0;

    printf("\n\t### Sum of odd numbers till n. ###\n\n");
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
            for (register int i = 1; i <= n; i += 2)
            {
                sum += i;
            }

            printf("Sum of odd numbers from 1 to %d, is %d.\n", n, sum);
        }
    }
    else
    {
        printf("Invalid input !\n");
    }

    return SUCCESS;
}