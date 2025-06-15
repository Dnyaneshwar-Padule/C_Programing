#include<stdio.h>
#define SUCCESS 0

int main()
{
    char ch = '\0';

    printf("Enter a character : ");
    scanf("%c", &ch);

    printf("The ASCII value of %c is %d.\n", ch,ch);

    return SUCCESS;
}