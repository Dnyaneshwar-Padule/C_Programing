#include<stdio.h>
#define SUCCESS 0
#define ARRAY_LENGTH 10

int main(){

    int arr_one[ARRAY_LENGTH] = {1,2,3,4,5,6,7,8,9,10};
    int arr_two[ARRAY_LENGTH] = {0};

    //copying arr_one to arr_two
    //and printing arr_one
    printf("\nArray One : [ ");
    for (int i = 0; i < ARRAY_LENGTH; i++){
        arr_two[i] = arr_one[i];
        printf("%-3d ", arr_one[i]);
    }
    printf("]");
    
    printf("\nArray Two : [ ");
    for (int i = 0; i < ARRAY_LENGTH; i++){
        printf("%-3d ", arr_two[i]);
    }
    printf("]\n");
    
    return SUCCESS;
}