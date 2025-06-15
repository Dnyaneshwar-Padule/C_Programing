#include<stdio.h>

enum Day {MON, TUE, WED, THU, FRI, SAT, SUN};

int main(){
    
    int today = SUN;

    switch (today)
    {
    case MON:
        printf("Today is Monday !\n");
        break;
    case TUE:
        printf("Today is Tuesday !\n");
        break;
    case WED:
        printf("Today is Wednesday !\n");
        break;
    case THU:
        printf("Today is Thursday !\n");
        break;
    case FRI:
        printf("Today is Friday !\n");
        break;
    case SAT:
        printf("Today is Saturday !\n");
        break;
    case SUN:
        printf("Today is Sunday !\n");
        break;
    default:
        printf("Invalid day !\n");
    }
    return 0;
}