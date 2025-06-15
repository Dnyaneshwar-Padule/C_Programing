#include<stdio.h>
#define SUCCESS 0

int main()
{
    int x = 0, y = 0;

    printf("\n### Calculate power (x^y) . ###\n\n");
    printf("Enter the value of x : ");
    if (! scanf("%d", &x))
    {
        printf("Invalid input !");
        return SUCCESS;
    }

    printf("Enter the value of y : ");
    if (scanf("%d", &y) )
    {
        long power = 1;

        for (int i = 0; i < y; i++)
        {
            power *= x; 
        }

        printf("%d^%d = %ld.\n", x, y, power);
        
    }
    else
    {
        printf("Invalid input !");
    }
    
    return SUCCESS;
}