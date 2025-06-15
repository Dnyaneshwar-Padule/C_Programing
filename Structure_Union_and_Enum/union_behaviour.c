#include<stdio.h>
#define SUCCESS 0

union var{
    int i;
    float f;
    char c;
    long long l;
};

typedef union var var;

int main(){
    var v;

    /*
        v will occupy 8 bytes, as the biggest datatype is long long, which occupies 8 bytes (Windows 64-bit)
    */

    v.i = 100;
    printf("Integer : %d, size : %d \n", v.i, sizeof(v));
    
    v.f = 98.80;
    printf("Float : %.2f, size : %d \n", v.f, sizeof(v));
    
    v.i = 'A';
    printf("Char : %c, size : %d \n", v.c, sizeof(v));

    //Now, tring to print the integer again
    //Only last assigned value is stored
    printf("Integer : %d", v.i); // Output is garbage value, 
    //actually it's printing ASCII value of 'A' (i.e. 65), which was the last assigned value

    return 0;
}
