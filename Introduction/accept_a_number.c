#include<stdio.h>

int main()
{
    int num = 0;

    printf("Enter a number : ");
    if ( scanf("%d", &num) == 1 ){
        printf("You entered %d.\n", num);
    }
    else
    {
        printf("Invalid input !");
        clear_buffer();
    }

    return 0;
}

void clear_buffer()
{
    char ch;
    while (  (ch = getchar()) != '\n' && ch != EOF );
}