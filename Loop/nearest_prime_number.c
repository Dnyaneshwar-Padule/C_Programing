#include<stdio.h>

int main()
{
    int num, i;

    printf("Enter a number : ");
    scanf("%d", &num);

    if(num < 1){
        //negative number
        printf("Nearest prime number is 2.\n");
        return 0;
    }

    for(i = 0; i <= num; i++)
    {
        int k;
        int nearest_greater_number = num + i;
        int nearest_smaller_number = num - 1;

        // first check forward
        for(k = 2; k < nearest_greater_number ; k++)
        {
            if( nearest_greater_number % k == 0)
            {
                break;
            }
        }

        if(k == nearest_greater_number)
        {
            printf("Nearest Prime number is %d\n", nearest_greater_number);
            break; // prime number bhetla, loop break kar
        }

        // check backward, same logic copy paste

        for(k = 2; k < nearest_smaller_number ; k++)
        {
            if( nearest_smaller_number % k == 0)
            {
                break;
            }
        }

        if(k == nearest_smaller_number)
        {
            printf("Nearest Prime number is %d\n", nearest_smaller_number);
            break; // prime number bhetla, loop break kar
        }

    }

    return 0;

}
