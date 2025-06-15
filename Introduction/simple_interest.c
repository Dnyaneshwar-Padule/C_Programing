#include<stdio.h>
#define SUCCESS 0

int main()
{
    float principle = 0, rate_of_interest = 0, time = 0, simple_interest = 0 ;
    
    printf("Enter    the   principle   : ");
    scanf("%f", &principle);

    printf("Enter the rate of interest : ");
    scanf("%f", &rate_of_interest);

    printf("Enter     the      time    : ");
    scanf("%f", &time);

    simple_interest = (principle * rate_of_interest * time) / 100.0;

    printf("The simple interest is %.2f.\n", simple_interest);

    return SUCCESS;
}