#include<stdio.h>
#define SUCCESS 0

int main()
{
    unsigned short age = 0;

    printf("Enter the age of candidate : ");
    scanf("%hu", &age);

    if (age >= 18)
    {
        printf("Candidate is eligible to vote.\n");
    }
    else
    {
        printf("Candidate is not eligible to vote.\n");
    }

    return SUCCESS;
}