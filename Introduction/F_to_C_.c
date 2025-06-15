#include<stdio.h>
#define SUCCESS 0

int main()
{
    float fahrenheit = 0, celcius = 0;

    printf("Enter the temperature in fahrenheit : ");
    scanf("%f", &fahrenheit);

    celcius = (fahrenheit - 32) * (5.0 / 9.0);

    printf("The temperature in celcius : %.2f /n", celcius);

    return SUCCESS;
}