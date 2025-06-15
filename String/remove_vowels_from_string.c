#include <stdio.h>
#include <string.h>

#define SUCCESS 0
#define TRUE 1
#define FALSE 0

int is_vowel(char);

int main(){
    char str[64];
    
    printf("Enter the string (up to 64 characters): ");
    fgets(str, sizeof(str), stdin);
    
    str[strlen(str)-1] = '\0';
    
    int i = 0, j = 0;
    while (str[i]) {
        if (!is_vowel(str[i])) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
    
    printf("String without vowels: %s\n", str);
    return SUCCESS;
}

int is_vowel(char ch){
    switch(ch){
        case 'a': 
        case 'A':
        case 'e': 
        case 'E':
        case 'i': 
        case 'I':
        case 'o': 
        case 'O':
        case 'u': 
        case 'U':
            return TRUE;
        default:
            return FALSE;
    }
}