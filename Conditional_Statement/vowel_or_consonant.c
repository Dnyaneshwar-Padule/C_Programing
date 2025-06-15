#include<stdio.h>
#define SUCCESS 0

int main()
{
    char letter = '\0';
 
    printf("Enter a letter : ");
    scanf("%c", &letter);

    if (   letter =='a' || letter =='A' || letter =='e' || letter =='E'
        || letter =='i' || letter =='I' || letter =='o' || letter =='O'
        || letter =='u' || letter =='U'
        )
    {
        printf("%c is a vowel.\n", letter);    
    }
    else
    {
        printf("%c is a consonant.\n", letter);     
    }
    
    /*
    switch (letter)
    {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
        printf("%c is a vowel.\n", letter);    
        break;
        default:    
        printf("%c is a consonant.\n", letter);     
    }
    */

    return SUCCESS;
}