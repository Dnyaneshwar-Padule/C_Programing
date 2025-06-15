#include<stdio.h>
#define SUCCESS 0
#define MAX_LENGTH 50
#define TRUE 1
#define FALSE 0
#define NOT_FOUND -1

void clear_buffer();
int accept_array(int*, int);
int take_input(int*);
int search(int*, int, int);

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
            int key = 0;
            int index = 0;

            printf("\nEnter the element to search : ");
            if(!scanf("%d", &key)){
                printf("Invalid input !");
                clear_buffer();
                return SUCCESS;
            }

            index = search(arr, len, key);
            
            if (index < 0){
                printf("The %d is not present in the array.\n", key);
            }
            else{
                printf("The element %d found at index: %d\n", key, index);
            }
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

int search(int* arr, int len, int key){
    for (int i = 0; i < len; i++){
        if (arr[i] == key){
            return i;
        }
    }
    return NOT_FOUND;
}