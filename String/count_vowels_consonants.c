#include<stdio.h>
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

int is_vowel(char);
int is_consonant(char);

int main(){
    
    char str[64] = {'\0'};
    unsigned int vowel_cnt = 0, consonant_cnt = 0;

    printf("Enter the string (upto 64 characters) : ");
    fgets(str, 64, stdin);

    for (int i = 0; str[i] ; i++){
        if (is_vowel(str[i]))  
            vowel_cnt++;
        else if (is_consonant(str[i]))
            consonant_cnt++;
    }

    printf("Total vowels : %d\n", vowel_cnt);
    printf("Total consonants : %d\n", consonant_cnt);

    return SUCCESS;
}

int is_vowel(char ch){
    int result = FALSE;
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
            result = TRUE;
    }
    return result;
}

int is_consonant(char ch){
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')){
        return ! is_vowel(ch);
    }
    return FALSE;
}