#include<stdio.h>
#include<string.h>
#define SUCCESS 0

int main(){
    char str[64] = {'\0'};

    printf("Enter the string (upto 64 characters) : ");
    fgets(str, 64, stdin);

    unsigned int word_cnt = 0;
    for (int i = 0; str[i] ; i++){
        if (str[i] == ' ' || str[i] == '\n'){
            word_cnt++;
            while (str[i] && (str[i] == ' ' || str[i] == '\n')) i++;
        }
    }
    
    printf("Total words in the String : %d\n", word_cnt);
    return SUCCESS;
}