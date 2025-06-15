#include <stdio.h>
#include <string.h>
#define SUCCESS 0

int main(){
    char str[64];
    
    printf("Enter the string (up to 64 characters): ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';
    int i = 0, j = 0;

    while (str[i]){
        if (str[i] != ' ')
            str[j++] = str[i];
        i++;
    }

    str[j] = '\0';
    printf("String without vowels: %s\n", str);
    return SUCCESS;
}