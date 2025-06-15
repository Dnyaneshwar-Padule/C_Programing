#include<stdio.h>
#define SUCCESS 0
#define MAX_LENGTH 50
#define TRUE 1
#define FALSE 0

void clear_buffer();
int accept_array(int*, int);
int take_input(int*);
unsigned int count_odd(int*, int);

int main(){
    int arr[50] = {0};
    int len;

    printf("\n### Search element in array ###\n\n");
    printf("How many elements (upto 50) : ");
    if (scanf("%d", &len)){
        
        if (len < 1 || len > 50){
            printf("Invalid array length.\n");
            return SUCCESS;
        }
        
        if (accept_array(arr, len)){
            unsigned int odd_count = count_odd(arr, len);
            printf("The number of odd elements is %d and the number of even elements is %d.\n", odd_count, (len - odd_count));
        }
        else{
            printf("Invalid input !\n");
            clear_buffer();
            return SUCCESS;
        }
    }
    else{
        printf("Invalid input !");
        clear_buffer();
    }
    return SUCCESS;
}

void clear_buffer(){
    char ch;
    while ( (ch = getchar()) != '\n' && ch != EOF );
}

int accept_array(int* arr, int len){
    for (int i = 0; i < len; i++){
        if (! take_input(&arr[i])){
            return FALSE;
        }
    }
    return TRUE;
}

int take_input(int* val){
    printf("Enter the number : ");
    return scanf("%d", val);
}

unsigned int count_odd(int* arr, int len){
    unsigned int odd_count = 0; 
    for (int i = 0; i < len; i++){
        if (arr[i] % 2)
            odd_count++;
    }
    return odd_count;
}