#include<stdio.h>
#include<string.h>
#define SUCCESS 0

void print_word(char*, int, int);
void reverse(char*, int, int);

int main(){
    char str[64] = {'\0'};

    printf("Enter the string (upto 64 characters) : ");
    fgets(str, 64, stdin);

    int  j = 0, max_len = 0, to, from;
    for (int i = 0; str[i] ; i++){
        if (str[i] == ' ' || str[i] == '\n'){
            reverse(str, j, i-1);
            while (str[i] && (str[i] == ' ' || str[i] == '\n')) i++;
            j = i;
        }
    }

    printf("%s\n", str);

    return SUCCESS;
}

void print_word(char* str, int from, int to){
    for (int i = from; i <= to; i++)
        printf("%c", str[i]);
    printf("\n");
}

void reverse(char* str, int from, int to){
    char ch;
    while (from < to){
        ch = str[from];
        str[from] = str[to];
        str[to] = ch;
        from++;
        to--;
    }
}