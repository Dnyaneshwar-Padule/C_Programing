#include<stdio.h>
#define SUCCESS 0

int main()
{
    float num_one = 0, num_two = 0;

    printf("Enter the first number  : ");
    scanf("%f", &num_one);

    printf("Enter the second number : ");
    scanf("%f", &num_two);

    if(num_one < num_two)
    {
        printf("%.2f is maximum.\n", num_two);
    }
    else if (num_one == num_two)
    {
        printf("Both numbers are equal.\n");
    }
    else
    {
        printf("%.2f is maximum.\n", num_one);
    }
    

    return SUCCESS;
}