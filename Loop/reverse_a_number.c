#include<stdio.h>
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

int main()
{
    int num = 0, reverse = 0;

    printf("\n### Reverse a number. ###\n\n");
    printf("Enter a number : ");
    if (scanf("%d", &num))
    {
        int remainder = 0;
        while (num != 0)
        {
            remainder = num % 10;
            reverse = (reverse * 10) + remainder;
            num /= 10;
        }

        printf("The reversed number is %d.\n", reverse);
    }
    else
    {
        printf("Invalid input !\n");
    }

    return SUCCESS;
}