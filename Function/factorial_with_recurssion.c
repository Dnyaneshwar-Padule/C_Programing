#include<stdio.h>
#define SUCCESS 0

void clear_buffer();
int take_input(int*);
int factorial(int);

int main()
{
    int num = 0;

    if (take_input(&num))
    {    
        printf("The factorial of %d is %d.\n", num, factorial(num));
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

int take_input(int *num)
{
    printf("Enter a number  :");
    return scanf("%d", num);
}

int factorial(int num)
{
    if (!num)
    {
        return 1;
    }

    return num * factorial(num - 1);
}