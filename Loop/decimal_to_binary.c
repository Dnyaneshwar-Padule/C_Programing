#include<stdio.h>
#define SUCCESS 0

int main()
{
    int num;

    printf("\n### Decimal to Binary ###\n\n");
    printf("Enter a number : ");
    if (scanf("%d", &num))
    {
        unsigned long binary = 0, multiplier = 1;
        int remainder = 0;

        while (num)
        {
            remainder = num % 2;
            binary += ((long)remainder * multiplier);
            multiplier *= 10;
            num /= 2;
        }

        printf("Binary value : %ld.\n", binary);
        
    }
    else
    {
        printf("Invalid input !\n");
    }
    
    return SUCCESS;
}