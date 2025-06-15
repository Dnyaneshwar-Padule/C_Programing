#include<stdio.h>
#define SUCCESS 0

int main()
{
    float celcius = 0, fahrenheit = 0;

    printf("Enter the temperature in Celcius : ");
    scanf("%f", &celcius);

    fahrenheit = ((9.0 / 5.0) * celcius) + 32;

    printf("The temperature in fahrenheit is %.2f.", fahrenheit);

    return SUCCESS;
}