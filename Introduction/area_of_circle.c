#include<stdio.h>
#define SUCCESS 0
#define PI 3.14

int main()
{
    float radius = 0, area = 0;

    printf("Enter the radius : ");
    scanf("%f", &radius);

    area = PI * (radius * radius);

    printf("The area of circle with radius %.2f is %.2f.", radius, area);

    return SUCCESS;
}