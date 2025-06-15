#include<stdio.h>
#define SUCCESS 0

int main()
{
    unsigned short year = 0;

    printf("Enter the year : ");
    scanf("%hu", &year);

    if ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) )
    {
        printf("%hu is a leap year.\n", year);
    }
    else
    {
        printf("%hu is not a leap year.\n", year);
    }
 
    return SUCCESS;
}