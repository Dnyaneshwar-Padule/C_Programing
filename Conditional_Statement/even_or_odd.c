#include<stdio.h>
#define SUCCESS 0

int main()
{
    int num = 0;

    printf("Enter the number : ");
    scanf("%d", &num);

    if(num % 2)
    {
        printf("%d is odd.\n", num);
    }
    else
    {
        printf("%d is even.\n", num);
    }

    //with ternary operator...
    //printf("%d is %s.\n", num, (num % 2) ? "odd" : "even");
    
    return SUCCESS;
}