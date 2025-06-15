#include<stdio.h>
#define SUCCESS 0

void clear_buffer();
int take_input(int*);
int reverse(int);

int main()
{
    int num = 0;

    if (take_input(&num))
    {    
        printf("The reverse of %d is %d.\n", num, reverse(num));
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

int reverse(int num)
{
    int reverse = 0;
    
    while (num)
    {
        reverse = (reverse * 10) + (num % 10);
        num /= 10; 
    }
    
    return reverse;
}