#include<stdio.h>
#define SUCCESS 0

int main(){
    
    char str[64] = {'\0'};
    unsigned int digit_cnt = 0, spaces_cnt = 0, special_chars_cnt = 0;

    printf("Enter the string (upto 64 characters) : ");
    fgets(str, 64, stdin);

    for (int i = 0; str[i] ; i++){
        if (str[i] >= '0' && str[i] <= '9')
            digit_cnt++;
        else if (str[i] == ' ')
            spaces_cnt++;
        else if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
            special_chars_cnt++;
    }

    printf("Total digits : %d\n", digit_cnt);
    printf("Total spaces : %d\n", spaces_cnt);
    printf("Total special chars : %d\n", special_chars_cnt);

    return SUCCESS;
}
