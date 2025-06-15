#include<stdio.h>
#include<string.h>
#define SUCCESS 0

void print_word(char*, int, int);

int main(){
    char str[64] = {'\0'};

    printf("Enter the string (upto 64 characters) : ");
    fgets(str, 64, stdin);

    int  j = 0;
    for (int i = 0; str[i] ; i++){
        if (str[i] == ' ' || str[i] == '\n'){
            print_word(str, j, i);
            while (str[i] && (str[i] == ' ' || str[i] == '\n')) i++;
            j = i;
        }
    }
    return SUCCESS;
}

void print_word(char* str, int from, int to){
    for (int i = from; i <= to; i++)
        printf("%c", str[i]);
    printf("\n");
}