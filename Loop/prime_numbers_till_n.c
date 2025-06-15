#include<stdio.h>
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

int main()
{
    int n = 0;

    printf("\n### Prime numbers till n. ###\n\n");
    printf("Enter a number : ");
    if (scanf("%d", &n))
    {
        if (n < 2)
        {
            printf("There are no prime numbers till %d.\n", n);
        }
        else
        {
            printf("Prime numbers till %d.\n", n);
            char is_prime;

            for (int i = 2; i <= n; i++)
            {
                is_prime = TRUE;

                for (int j = 2 ; j < i; j++)
                {
                    if(! (i % j) )
                    {
                        is_prime = FALSE;
                        break;
                    }
                }

                (is_prime) ? printf("%d\n", i) : FALSE ;
            }
        
        }
      
    }
    else
    {
        printf("Invalid input !\n");
    }
    
    return SUCCESS;
}