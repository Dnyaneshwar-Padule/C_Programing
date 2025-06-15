#include<stdio.h>
#include<string.h>

#define SUCCESS 0

int main(){
    char str[64] = {'\0'};
    
    printf("Enter the string (upto 64 characters) : ");
    fgets(str, 64, stdin);
    int j = strlen(str) - 1, i = 0;
    str[j--] = '\0';
    for (; i < j; i++, j--){
        if (str[i] != str[j])
            break;
    }
    
    if (i > j || i == j){
        printf("Entered string %s is a palindrome.\n", str);
    }
    else{
        printf("Entered string %s is not a palindrome.\n", str);
    }

    return SUCCESS;
}