#include<stdio.h>
#define SUCCESS 0
#define MAX_LENGTH 50
#define TRUE 1
#define FALSE 0

void clear_buffer();
int accept_array(int*, int);
int take_input(int*);
unsigned int count_frequency(int*, int,int);

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
            int element = 0;
            unsigned int frequency_count = 0;

            printf("\nEnter the element to count it's frequency : ");
            if ( scanf("%d", &element)){
                frequency_count = count_frequency(arr, len, element);
                if (!frequency_count){
                    printf("The element is not present in the array.\n");
                }
                else{
                    printf("The %d is occured %d times in the array. \n", element, frequency_count);
                }
            }
            else{
                printf("Invalid input !\n");
                clear_buffer();
                return SUCCESS;
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

unsigned int count_frequency(int* arr, int len, int element){
    unsigned int count = 0; 
    for (int i = 0; i < len; i++){
        if (arr[i] == element)
            count++;
    }
    return count;
}