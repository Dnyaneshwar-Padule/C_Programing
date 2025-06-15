#include<stdio.h>
#define SUCCESS 0

int main()
{
    char ch;

    printf("Enter the (valid) ASCII value : ");
    scanf("%d", &ch);

    printf("The character with ASCII value %d is '%c'.\n", ch, ch);

    return SUCCESS;
}