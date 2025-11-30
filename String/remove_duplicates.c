#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* removeDuplicates(char* s) {
    int i,j = 0, n = -1;

    for( i = 1; s[i]; ++i, j++){
        char ch1 ,ch2;
        ch1 = s[i]; ch2 = s[j];

        if(ch1 != ch2){
            s[++n] = ch2;
            printf("%c\t", ch2);
        }
        else{
            i++;
            j++;
        }
    }

    s[++n] = s[j];
    s[++n] = '\0';
    printf("%d -- %d -- %d\n", i, j, n);
    
    if(i == j)
        return s;
    //return removeDuplicates(s);
}

int main(){

    char *str = (char*)malloc(sizeof(char) * 11);
    strcpy(str, "abbac");
    printf("%s\n", str);
    str = removeDuplicates(str);
    printf("%s\n", str);

    free(str);
    return 0;
}