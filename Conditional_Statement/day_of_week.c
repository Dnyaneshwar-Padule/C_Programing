#include<stdio.h>
#define SUCCESS 0

int main()
{

    char day_of_week = 0;

    printf("Enter the day of week (1-7) : ");
    scanf("%d", &day_of_week);

    switch (day_of_week)
    {
    case 1:
        printf("It's Monday.\n");
        break;
    case 2:
        printf("It's Tuesday.\n");
        break;
    case 3:
        printf("It's Wednesday.\n");
        break;
    case 4:
        printf("It's Thursday.\n");
        break;
    case 5:
        printf("It's Friday.\n");
        break;
    case 6:
        printf("It's Saturday !\n");
        break;
    case 7:
        printf("It's Sunday !!\n");
        break;
    default:
        printf("Invalid Input.\n");    
    }

    return SUCCESS;
}