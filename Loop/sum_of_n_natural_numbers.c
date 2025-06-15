#include<stdio.h>
#define SUCCESS 0

int main()
{
    int n = 0, sum = 0;

    printf("\n### Sum of n natural numbers. ###\n");
    printf("Enter the value of n : ");
    if (scanf("%d", &n))
    {
        if (n < 1)
        {
            printf("Please enter a value greater than 0.\n");
            printf("Entered value (n) : %d.\n", n);
        }
        else
        {
            for (register int i = 1; i <= n; i++)
            {
                sum += i;
            }
            
            printf("Sum of %d natural numbers (from 1 to %d) is %d.\n", n, n, sum);
        }
    }
    else
    {
        printf("Invalid input !.\n");
    }
    
    return SUCCESS;
}