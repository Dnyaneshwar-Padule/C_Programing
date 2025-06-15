#include<stdio.h>
#define SUCCESS 0

void clear_buffer();
long my_pow(int, int);

int main()
{
    int x = 0, y = 0;

    printf("Enter the value of x : ");
    if (! scanf("%d", &x))
    {
        printf("Invalid input !\n");
        clear_buffer();
        return SUCCESS;
    }

    printf("Enter the value of y : ");
    if (scanf("%d", &y))
    {
        printf("%d^%d = %ld\n", x, y, my_pow(x,y));
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
    while ( (ch = getchar() != '\n') && ch != EOF );
}

long my_pow(int x, int y)
{
    unsigned long result = 1;
    for (int  i = 1; i <= y; i++)
    {
        result *= x;
    }
    return result;
}