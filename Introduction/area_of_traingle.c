#include<stdio.h>
#define SUCCESS 0

int main()
{
    float base = 0, height = 0, area = 0;

    printf("Enter  the  base : ");
    scanf("%f", &base);

    printf("Enter the height : ");
    scanf("%f", &height);

    area = 0.5 * base * height;

    printf("The area is %.2f.\n", area);

    return SUCCESS;
}