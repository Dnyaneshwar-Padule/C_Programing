#include<stdio.h>
#define SUCCESS 0

int main()
{
 
    int num = 0;

    printf("Enter a number : ");
    scanf("%d", &num);

    if ((num % 5 == 0) && (num % 11 == 0))
    {
        printf("%d is divisible by both 5 and 11.\n", num);
    }
    else if (num % 5 == 0)
    {
        printf("%d is divisible by 5.\n", num);
    }
    else if (num % 11 == 0)
    {
        printf("%d is divisible by 11.\n", num);
    }
    else
    {
        printf("%d is neither divisible by 5 nor 11.\n", num);
    }
    
    
    
    

    return SUCCESS;
}