#include<stdio.h>
#define SUCCESS 0

int main()
{
    int num = 0;

    printf("\n### Check Prime. ###\n\n");
    printf("Enter a number : ");
    
    if (scanf("%d", &num))
    {
        if (num < 2)
        {
            printf("%d is not a prime number !\n", num);
        }
        else
        {
            int i;
            for (i = 2 ; i < num; i++)
            {
                if(! (num % i) )
                {
                    break;
                }
            }

            if (i == num)
            {
                printf("%d is a prime number.\n", num);
            }
            else
            {
                printf("%d is not a prime number.\n", num);
            }        
        }
      
    }
    else
    {
        printf("Invalid input !\n");
    }
    
    return SUCCESS;
}