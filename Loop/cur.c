#include<stdio.h>
#include<unistd.h>
#include<windows.h>

int main()
{
    int i=10;

    for ( i = 9; i >= 0; i--)
    {
        printf("%d",i);
        Beep(58900,750);
        sleep(1);
        printf("\b");
    }

    printf("\n*****BOOM****\n");
   
    return 101;
    
}