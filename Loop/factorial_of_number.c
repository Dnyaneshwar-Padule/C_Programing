#include<stdio.h>
#define SUCCESS 0

int main()
{
    int num = 0, factorial = 1;

    printf("\n### Factorial of number. ###\n\n");
    printf("Enter the number : ");
    if (scanf("%d", &num))
    {
        if (num < 1)
        {
            printf("Please enter a number greater than 0.");
            printf("Entered number : %d.\n", num);
        }
        else
        {
            for (int i = num; i >= 1; i--)
            {
                factorial *= i;
            }

            printf("Factorial of %d is %d.\n", num, factorial);   
        }        
    }
    else
    {
        printf("Invalid input !\n");
    }

    return SUCCESS;
}