#include<stdio.h>
#define SUCCESS 0

int add(int, int);
void clear_buffer();

int main()
{
    int num_one = 0, num_two = 0;

    printf("Enter the first number : ");
    if (!scanf("%d", &num_one))
    {
        printf("Invalid input !\n");
        clear_buffer();
        return SUCCESS;
    }

    printf("Enter the second number : ");
    if (scanf("%d", &num_two))
    {
        printf("Addition of %d and %d is %d.\n", num_one, num_two, add(num_one, num_two));
    }
    else
    {
        printf("Invalid input !\n");
        clear_buffer();
    }

    return SUCCESS;
}

int add(int a, int b)
{
    return a + b;
}

void clear_buffer()
{
    char ch;
    while (  (ch = getchar()) != '\n' && ch != EOF );
}