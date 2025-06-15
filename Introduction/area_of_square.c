#include<stdio.h>
#define SUCCESS 0

int main()
{
    float side = 0, area = 0;

    printf("Enter the side : ");
    scanf("%f", &side);

    area = side * side;

    print("The area is %.2f.\n", area);
    
    return SUCCESS;
}