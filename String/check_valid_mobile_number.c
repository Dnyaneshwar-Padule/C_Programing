#include<stdio.h>
#include<string.h>
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

int is_valid_mobile_number(char*);

int main(){
    char str[20] = {'\0'};

    printf("Enter the mobile number : ");
    fgets(str, 20, stdin);
    str[strlen(str) - 1] = '\0'; // To remove the \n

    if (is_valid_mobile_number(str)){
        printf("The entered string is a valid mobile number.");
    }
    else{
        printf("The entered string is not a valid mobile number.");
    }
    
    return SUCCESS;
}

int is_valid_mobile_number(char* str){
    if (strlen(str) != 10)
        return FALSE;
    
    if (str[0] != '6' && str[0] != '7' && str[0] != '8' && str[0] != '9')
        return FALSE;
    
    
    for (int i = 0; str[i] ; i++)
        if ( ! (str[i] >= '0' && str[i] <= '9') )
            return FALSE;

    return TRUE;
}
