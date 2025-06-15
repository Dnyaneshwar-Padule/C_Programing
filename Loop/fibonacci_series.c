#include<stdio.h>
#define SUCCESS 0

int main()
{
    int n = 0;

    printf("\n### Fibonacci Series till n ###\n\n");
    printf("Enter the value of n : ");
    if (scanf("%d", &n))
    {
        if (n < 0)
        {
            printf("n should be 0 or greater than 0.\n");
            printf("Entered value : %d\n", n);
        }
        else
        {
            int f1 = 1, f2 = 0 , f3 = 0;
            while(n-->=0)
            {
                printf("%d, ", f3);
                f3 = f1 + f2;
                f1 = f2;
                f2 = f3;
            }
        }        
    }
    else
    {
        printf("Invalid input !");
    }

    return SUCCESS;
}