#include<stdio.h>

int my_strlen(char*);

int main(){
    char str[32] = "Athrva";
    printf("Length : %d\n", my_strlen(str));

    return 0;
}

int my_strlen(char *str) {
    int len = 0;
    while (*str++) len++;
    return len;
}

