#include<stdio.h>
#define SUCCESS 0

void clear_buffer();
int take_input(int*);
int is_prime(int);

int main()
{
    int num = 0;

    if (take_input(&num))
    {    
        if (is_prime(num))
        {
            printf("%d is a prime number.\n", num);
        }
        else
        {
            printf("%d is not a prime number.\n", num);
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

int take_input(int *num)
{
    printf("Enter a number  :");
    return scanf("%d", num);
}

int is_prime(int num)
{
    int i = 2;
    
    for (; i < num; i++)
    {
        if(num % i == 0)
            break;
    }

    return i == num;
}