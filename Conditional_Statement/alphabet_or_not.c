#include<stdio.h>
#define SUCCESS 0

int main()
{
 
    char character;

    printf("Enter a character : ");
    scanf("%c", &character);

    if((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') )
    {
        printf("%c is an alphabet.\n", character);
    }
    else
    {
        printf("%c is not an alphabet.\n", character);
    }
    

    return SUCCESS;
}