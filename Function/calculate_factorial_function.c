#include<stdio.h>
#define SUCCESS 0
#define INVALID_NUMBER -1

void clear_buffer();
int calculate_factorial(int);

int main()
{
    int num = 0;
    printf("Enter the number : ");
    if (scanf("%d", &num))
    {
        int factorial = calculate_factorial(num);
        if (factorial == INVALID_NUMBER)
        {
            printf("Please enter a number greater than 0.\n");
        }
        else
        {
            printf("Factorial : %d.\n", factorial);
        }
    }
    else
    {
        printf("Invalid input !\n");
        clear_buffer();   
    }
    
    return SUCCESS;
}

void clear_buffer()
{
    char ch;
    while (  (ch = getchar()) != '\n' && ch != EOF );
}

int calculate_factorial(int n)
{
    if(n < 1)
    {
        return INVALID_NUMBER;   
    }

    int factorial = 1;

    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    
    return factorial;
}