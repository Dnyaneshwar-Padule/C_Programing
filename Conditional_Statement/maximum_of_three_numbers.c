#include<stdio.h>
#define SUCCESS 0

int main()
{
 
    float num_one = 0, num_two = 0, num_three = 0;

    printf("Enter the first  number : ");
    scanf("%f", &num_one);

    printf("Enter the second number : ");
    scanf("%f", &num_two);

    printf("Enter the third  number : ");
    scanf("%f", &num_three);

    if (num_one == num_two && num_one == num_three)
    {
        printf("All numbers are equal.\n");
    }
    else if(num_one > num_two && num_one > num_three)
    {
        //num_one is biggest
        printf("%.2f is biggest.\n", num_one);
    }
    else if (num_two > num_three)
    {
        //num_two is biggest
        printf("%.2f is biggest.\n", num_two);
    }
    else 
    {
        //num_three is biggest
        printf("%.2f is biggest.\n", num_three);
    }
    
    return SUCCESS;
}