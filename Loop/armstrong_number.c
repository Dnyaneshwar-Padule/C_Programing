#include<stdio.h>
#define SUCCESS 0

int main()
{
    int num = 0;

    printf("\n### Armstrong number. ###\n\n");
    printf("Enter a number : ");
    if (scanf("%d", &num))
    {

        if (num < 0)
        {
            printf("Negative numbers are not considered as armstrong numbers.\n");
        }
        else
        {
            int temp = num, sum_of_cube_of_digits = 0, digit = 0;
            while (temp)
            {
                digit = temp % 10;
                sum_of_cube_of_digits += digit * digit * digit;
                temp /= 10;
            }
    
            if (num == sum_of_cube_of_digits)
            {
                printf("%d is a armstrong number.\n", num);
            }
            else
            {
                printf("%d is not a armstrong number.\n", num);
            } 
        }
    }
    else
    {
        printf("Invalid input !\n");
    }

    return SUCCESS;
}