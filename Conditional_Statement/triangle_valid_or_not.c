#include<stdio.h>
#define SUCCESS 0

int main()
{
    float side_one = 0, side_two = 0, side_three = 0;

    printf("Enter the length of first  side : ");
    scanf("%d", &side_one);
    
    printf("Enter the length of second side : ");
    scanf("%d", &side_two);
    
    printf("Enter the length of third  side : ");
    scanf("%d", &side_three);

    if ((side_one + side_two) > side_three)
    {
        printf("It's a triangle.");
    }
    else
    {
        printf("It's not a triangle.");
    }

    return SUCCESS;
}