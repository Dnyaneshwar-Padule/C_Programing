#include<stdio.h>
#define SUCCESS 0

int main()
{
    int num = 0, number_of_digits = 0;

    printf("\n### Print number of digits in a number. ###\n\n");
    printf("Enter a number : ");
    if (scanf("%d", &num))
    {
        int temp = num;

        while (temp != 0)
        {
            temp /= 10;
            number_of_digits ++;
        }

        printf("There are %d digits in %d.\n", number_of_digits, num);
           
    }
    else
    {
        printf("Invalid input !\n");
    }

    return SUCCESS;
}