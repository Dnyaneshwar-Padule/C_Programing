#include<stdio.h>
#define SUCCESS 0

void clear_buffer();
int is_even(int);

int main()
{
    int num = 0;
    printf("Enter the number : ");
    if(scanf("%d", &num))
    {
        if (is_even(num))
        {
            printf("%d is even.\n", num);
        }
        else
        {
            printf("%d is odd.\n", num);
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

int is_even(int num)
{
    return ! (num % 2);   
}