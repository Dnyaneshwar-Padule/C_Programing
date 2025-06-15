#include<stdio.h>
#include<string.h>
#define SUCCESS 0

int main(){
    char str[64] = {'\0'};

    printf("Enter the string (upto 64 characters) : ");
    fgets(str, 64, stdin);
    str[strlen(str) - 1] = '\0';

    for (int i = 0; str[i] ; i++){
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    
    printf("String with toggled case : %s", str);
    
    return SUCCESS;
}