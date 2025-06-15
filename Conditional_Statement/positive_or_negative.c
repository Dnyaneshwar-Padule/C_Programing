#include<stdio.h>
#define SUCCESS 0

int main()
{
    int num = 0;

    printf("Enter the number : ");
    scanf("%d", &num);

    if(num < 0)
    {
        printf("%d is negative.\n", num);
    }
    else
    {
        printf("%d is positive.\n", num);
    }


    //with ternary operator...
    //printf("%d is %s.\n", num, (num < 0) ? "negative" : "positive");
    
    return SUCCESS;
}