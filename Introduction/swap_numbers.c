#include<stdio.h>
#define SUCCESS 0

int main()
{
    int a = 100, b = 200;
    
    printf("Before swapping, a = %d, b = %d.\n", a, b);
    /*
        //First way
        //with a third variable 
        int temp = a;
        a = b;
        b = temp;
    */

    /*
        //Second way
        a = a + b;
        b = a - b;
        a = a - b;
    */
    
    //Third way
    a = a * b;
    b = a / b;
    a = a / b;

    printf("After  swapping, a = %d, b = %d.\n", a, b);


    return SUCCESS;
}