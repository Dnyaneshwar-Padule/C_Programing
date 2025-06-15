#include<stdio.h>
#define SUCCESS 0

int main()
{
    int n;

    printf("\n### Pattern printing : Numbered right-angled traingle. ###\n\n");
    printf("Enter the value of n : ");
    if (scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                printf("%d ",j);
            }
            printf("\n");
        }
        
    }
    else
    {
        printf("Invalid input !\n");
    }
    
    return SUCCESS;
}

/*
Output:

### Pattern printing : Numbered right-angled traingle. ###

Enter the value of n : 5
1 
1 2
1 2 3
1 2 3 4
1 2 3 4 5 

*/