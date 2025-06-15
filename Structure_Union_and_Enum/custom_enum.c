#include<stdio.h>

enum Status { OFF = 0, ON = 5, ERROR = 100 };

int main(){

    //int status = 0; // Off
    // int status = 5; // On
    // int status = 100; // Error
    int status = 10; // Invalid Status

    switch (status)
    {
    case ON:
        printf("It's On\n");
        break;
    case OFF:
        printf("It's Off\n");
        break;
    case ERROR:
        printf("There is an error \n");
        break;
        default:
        printf("Invalid status\n");
    }
    return 0;
}