#include<stdio.h>
#include<string.h>
#define SUCCESS 0

void print_word(char*, int, int);

int main(){
    char str[64] = {'\0'};

    printf("Enter the string (upto 64 characters) : ");
    fgets(str, 64, stdin);

    int  j = 0, max_len = 0, to, from;
    for (int i = 0; str[i] ; i++){
        if (str[i] == ' ' || str[i] == '\n'){
            if ((i - j) > max_len){
                to = i;
                from = j;
                max_len = i - j;
            }
            while (str[i] && (str[i] == ' ' || str[i] == '\n')) i++;
            j = i;
        }
    }

    print_word(str, from, to);

    return SUCCESS;
}

void print_word(char* str, int from, int to){
    for (int i = from; i <= to; i++)
        printf("%c", str[i]);
    printf("\n");
}