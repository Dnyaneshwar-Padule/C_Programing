#include<stdio.h>
#define SUCCESS 0
#define MAX_MULTIPLIER 10

int main()
{
    int num = 0;

    printf("\n\t### Multiplication table. ###\n\n");
    printf("Enter the number : ");
    if (scanf("%d", &num))
    {
        if(num < 1)
        {
            printf("Please enter a value greater than 0.\n");
            printf("Entered value : %d.\n", num);
        }
        else
        {
            for (register int i = 1; i <= MAX_MULTIPLIER ; i++)
            {
                printf("%-3d X %3d = %3d\n", num, i, (num * i));
            }
        }
    }
    else
    {
        printf("Invalid input !\n");
    }

    return SUCCESS;
}