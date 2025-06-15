#include<stdio.h>
#define SUCCESS 0

int main()
{
    float length = 0, breadth = 0, perimeter = 0;

    printf("Enter  the length : ");
    scanf("%f", &length);

    printf("Enter the breadth : ");
    scanf("%f", &breadth);

    perimeter = 2 * (length * breadth);
    
    printf("The perimeter is %.2f.\n", perimeter);

    return SUCCESS;
}