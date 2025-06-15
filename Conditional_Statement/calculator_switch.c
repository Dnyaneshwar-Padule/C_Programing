#include<stdio.h>
#define SUCCESS 0

int main()
{
 
    char operation = '\0';
    float num_one = 0, num_two = 0, ans = 0;

    printf("What do you want to do (+, -, *, /) : ");
    scanf("%c", &operation);

    switch (operation)
    {
    case '+':
        printf("Enter the  first number : ");
        scanf("%f", &num_one);
        printf("Enter the second number : ");
        scanf("%f", &num_two);
        ans = num_one + num_two;
        printf("Addition of %.2f and %.2f is %.2f.\n", num_one, num_two, ans);    
        break;
        
    case '-':
        printf("Enter the  first number : ");
        scanf("%f", &num_one);
        printf("Enter the second number : ");
        scanf("%f", &num_two);
        ans = num_one - num_two;
        printf("Subtraction of %.2f and %.2f is %.2f.\n", num_one, num_two, ans);
        break;
    
    case '*':
        printf("Enter the  first number : ");
        scanf("%f", &num_one);
        printf("Enter the second number : ");
        scanf("%f", &num_two);
        ans = num_one *  num_two;
        printf("Multiplication of %.2f with %.2f is %.2f.\n", num_one, num_two, ans);
        break;
    
    case '/':
        printf("Enter the  first number : ");
        scanf("%f", &num_one);
        printf("Enter the second number : ");
        scanf("%f", &num_two);
        ans = num_one / num_two;
        printf("Division of %.2f with %.2f is %.2f.\n", num_one, num_two, ans);
        break;
    
    default:
        printf("Invalid Operation !\n");
    }

    return SUCCESS;
}