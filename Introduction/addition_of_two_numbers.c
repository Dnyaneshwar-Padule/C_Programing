#include<stdio.h>
#define SUCCESS 0

int main()
{
    int num_one = 0, num_two = 0, sum = 0;

    printf("Enter the first number : ");
    scanf("%d", &num_one);

    printf("Enter the second number : ");
    scanf("%d", &num_two);

    sum = num_one + num_two;

    printf("Addition of %d and %d is %d.", num_one, num_two, sum);

    return SUCCESS;
}