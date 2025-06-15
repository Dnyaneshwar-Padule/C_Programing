#include<stdio.h>
#define SUCCESS 0

void clear_buffer();
void print_maximum(int, int, int);

int main()
{
    int num_one = 0, num_two = 0, num_three = 0;

    printf("Enter the first  number : ");
    if (! scanf("%d", &num_one))
    {
        printf("Invalid input !\n");
        clear_buffer();
        return SUCCESS;
    }    
    
    printf("Enter the second number : ");
    if (! scanf("%d", &num_two))
    {
        printf("Invalid input !\n");
        clear_buffer();
        return SUCCESS;
    }    

    printf("Enter the third  number : ");
    if (scanf("%d", &num_three))
    {
        print_maximum(num_one, num_two, num_three);
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

void print_maximum(int a, int b, int c)
{
    if (a == b && a == c)
    {
        printf("All numbers are equal.\n");
    }
    else if (a > b && a > c)
    {
        printf("Maximum number is %d.\n", a);
    }
    else if (b > c)
    {
        printf("Maximum number is %d.\n", b);
    }
    else
    {
        printf("Maximum number is %d.\n", c);
    }
    
}