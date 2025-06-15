#include<stdio.h>
#define SUCCESS 0

int main()
{
 
    float length = 0, breadth = 0, area = 0;

    printf("Enter the length of rectangle  : ");
    scanf("%f", &length);
    
    printf("Enter the breadth of rectangle : ");
    scanf("%f", &breadth);

    area = length * breadth;

    printf("The area of rectangle with length %.2f and breadth %.2f is %.2f.\n", length, breadth, area);
    
    return SUCCESS;
}