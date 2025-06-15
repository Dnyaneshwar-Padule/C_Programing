#include<stdlib.h>

int mystrlen(char* str){
    int i = 0;
    while (str[i])i++;
    return i;
}

int mystrcmp(char* str_one, char* str_two){
    int i = 0;
    while (str_one[i] && str_two[i] && str_one[i] == str_two[i]) i++;
    return str_one[i] - str_two[i]; // classic way
}

char* mystrcpy(char* destination, char* source){
    int i = 0;
    while (source[i]){
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
    return destination;
}

char* mystrcat(char* destination, char* source){
    int i = 0;
    while (destination[i]) i++;
        int j = 0;
    while (source[j]) destination[i++] = source[j++];
    destination[i] = '\0';
    return destination;
}

int mystrchr(char* str, char ch){
    int i = 0;
    while (str[i]){
        if (str[i] == ch)
            return i;
        i++;
    }
    return -1;
}

int mystrstr(char* str, char* substr) {
    int i, j;
    for (i = 0; str[i]; i++) {
        for (j = 0; substr[j]; j++) {
            if (str[i + j] != substr[j])
                break;
        }
        if (substr[j] == '\0')
            return i;
    }
    return -1;
}

char* mystrrev(char* str){
    int i = 0, j = mystrlen(str) - 1;
    char temp;
    while (i < j){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return str;
}

char* mystrupr(char* str){
    int i = 0;
    while (str[i]){
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        i++;
    }
    return str;
}

char* mystrlwr(char* str){
    int i = 0;
    while (str[i]){
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
    }
    return str;
}

char* mystrdup(char *original){
    int len = mystrlen(original), i = 0;
    char* duplicate = (char*) malloc(sizeof(char) * len + 1);
    while (original[i]){
        duplicate[i] = original[i];
        i++;
    }
    duplicate[i] = '\0';
    return duplicate;
}

