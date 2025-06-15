#include<stdio.h>
#define SUCCESS 0

int main()
{
    int num = 0, sum_of_digits = 0;

    printf("\n### Print sum of digits in a number. ###\n\n");
    printf("Enter a number : ");
    if (scanf("%d", &num))
    {
        int temp = num;
        while (temp != 0)
        {
            sum_of_digits += temp % 10;
            temp /= 10;
        }

        printf("Sum of digits in %d is %d.\n", num, sum_of_digits);
           
    }
    else
    {
        printf("Invalid input !\n");
    }

    return SUCCESS;
}