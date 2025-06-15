#include<stdio.h>
#define SUCCESS 0
#define MAX_ARRAY_SIZE 50
#define TRUE 1
#define FALSE 0

void clear_buffer();
int take_input(int*);
void display_array(int*, int);
int accept_array(int*, int);
int get_max(int*, int);

int main()
{
    int arr[MAX_ARRAY_SIZE];
    int len = 0;

    printf("How many elements (0-50) : ");
    if (scanf("%d", &len)){
        if (len < 0 || len > 50){
            printf("Invalid number of array elements.\n");
            printf("Array elements should be from 0 to 50.\n");
            printf("Entered no. of elements is %d.\n", len);
            return SUCCESS;
        }
        
        if(accept_array(arr, len)){
            display_array(arr, len);
            printf("Maximum in the array : %d.\n", get_max(arr, len));
        }
        else{
            clear_buffer();
            printf("Entered invalid value.\n");
        }
    }
    else{
        printf("Invalid input !\n");
    }
    
    return SUCCESS;
}

void clear_buffer(){
    char ch;
    while (  (ch = getchar()) != '\n' && ch != EOF );
}

int take_input(int *num){
    printf("Enter a number : ");
    return scanf("%d", num);
}

void display_array(int* arr, int len){
    printf("Array elements : ");

    if (len == 0){
        printf("[]\n");
        return;
    }

    printf("[");
    for (int i = 0; i < len - 1 ; i++){
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[len-1]);
}

int accept_array(int* arr, int len){
    for (int i = 0; i < len; i++){
        if (! take_input(&arr[i])){
            return FALSE; 
        }
    }
    return TRUE;
}

int get_max(int* arr, int len){
    int max = arr[0];
    for (int i = 0; i < len; i++){
        max = (arr[i] > max) ? arr[i] : max ;
    }
    return max;
}
