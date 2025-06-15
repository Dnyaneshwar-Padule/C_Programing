#include<stdio.h>
#include<string.h>
#define SUCCESS 0

int main(){
    char str[64] = {'\0'};

    printf("Enter the string (upto 64 characters) : ");
    fgets(str, 64, stdin);
    
    int i = 0, j = strlen(str) - 1;
    char temp = '\0';
    str[j--] = '\0';
    
    while (i < j){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    printf("Reversed string : %s", str);
    
    return SUCCESS;
}