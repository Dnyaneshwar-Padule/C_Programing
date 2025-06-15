#include<stdio.h>
#define SUCCESS 0

int main()
{
    char letter  = '\0';

    printf("Enter the letter : ");
    scanf("%c", &letter);

    if(letter >= 'A' && letter <= 'Z')
    {
        printf("%c is a uppercase letter.\n", letter);
    }
    else if (letter >= 'a' && letter <= 'z')
    {
        printf("%c is a lowercase letter.\n", letter);
    }
    else if (letter >= '0' && letter <= '9')
    {
        printf("%c is a digit.\n", letter);
    }
    else
    {
        printf("%c is a special symbol.\n", letter);
    }
 
    return SUCCESS;
}