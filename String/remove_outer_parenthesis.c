#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* removeOuterParentheses(char* s) {
    if ( !s ) return s;
    int outer = 0, inner = 0, n = -1;

    for(int i = 0; s[i]; ++i){
        char ch = s[i];
        if(outer == 0){
            if(ch == '(') outer = 1;
        }
        else{
            if(ch == '('){
                s[++n] = ch;
                inner++;
            }
            else{
                if(inner == 0) outer = 0;
                else{
                    s[++n] = ch;
                    inner--;
                } 
            }
        }
    }
    s[++n] = '\0';
    return s;
}

int main(){

    char *str = (char*)malloc(sizeof(char) * 11);
    strcpy(str, "(()())(())");
    printf("%s\n", str);
    str = removeOuterParentheses(str);
    printf("%s\n", str);

    free(str);
    return 0;
}