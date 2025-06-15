#include<stdio.h>
#define SUCCESS 0

//Date : 22-05-2025
//Rate : 1 INR = 0.012 USD

int main()
{
    float inr = 0, usd = 0;

    printf("Enter the amount in Rupees : ");
    scanf("%f", &inr);

    usd = inr * 0.012;

    printf("The amount in Dollers is %.2f.\n", usd);
    
    return SUCCESS;
}