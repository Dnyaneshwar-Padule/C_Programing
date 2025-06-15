#include<stdio.h>
#define SUCCESS 0

int main(){
    
    char str[64] = {'\0'};
    int frequency[26] = {0};

    printf("Enter the string (upto 64 characters) : ");
    fgets(str, 64, stdin);

    for (int i = 0; str[i] ; i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            frequency[str[i] - 'A']++;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
            frequency[str[i] - 'a']++;
    }

    //It also counts the /n (enter)
    printf("\nFrequency of every character\n\n");
    for (int i = 0; i < 26; i++){
        printf("%c -> [%-2d]\n", (i+'a'), frequency[i]);
    }
    
    return SUCCESS;
}
