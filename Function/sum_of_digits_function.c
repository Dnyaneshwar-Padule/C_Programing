#include<stdio.h>
#define SUCCESS 0

void clear_buffer();
int take_input(int*);
int sum_of_digits(int);

int main()
{
    int num = 0;

    if (take_input(&num))
    {    
        printf("The sum of digits in %d is %d.\n", num, sum_of_digits(num));
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

int sum_of_digits(int num)
{
    int sum = 0;
    
    while (num)
    {
        sum += (num % 10);
        num /= 10; 
    }
    
    return sum;
}