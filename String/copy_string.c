#include<stdio.h>
#include<string.h>
#define SUCCESS 0

int main(){
    char str[64] = {'\0'};
    char copied_str[64] = {'\0'};

    printf("Enter the string (upto 64 characters) : ");
    fgets(str, 64, stdin);
    strcpy(copied_str, str);
    printf("Copied string : %s", copied_str);
    
    return SUCCESS;
}