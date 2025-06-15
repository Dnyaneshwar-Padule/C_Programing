#include<stdio.h>
#define SUCCESS 0

int main(){
    char str[64] = {'\0'};

    printf("Enter the string (upto 64 characters) : ");
    fgets(str, 64, stdin);
    printf("Entered string : %s", str);
    
    return SUCCESS;
}