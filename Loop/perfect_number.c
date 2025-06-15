#include<stdio.h>
#define SUCCESS 0

int main()
{
    int num = 0;

    printf("\n### Perfect number ###\n\n");
    printf("Enter the number : ");
    if (scanf("%d", &num))
    {
        int sum_of_divisors = 0;

        for (int i = 1; i < num; i++)
        {
            sum_of_divisors += (num % i) ? 0 : i ;
        }

        if (sum_of_divisors == num)
        {
            printf("%d is a perfect number.\n", num);
        }
        else
        {
            printf("%d is not a perfect number.\n", num);
        }
 
    }
    else
    {
        printf("Invalid input !\n");
    }
    
    return SUCCESS;
}