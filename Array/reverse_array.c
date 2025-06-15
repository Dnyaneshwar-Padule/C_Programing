#include<stdio.h>
#define SUCCESS 0
#define ARRAY_LENGTH 10

int main(){

    int arr[ARRAY_LENGTH] = {1,2,3,4,5,6,7,8,9,10};

    printf("\nOriginal Array : [ ");
    for (int i = 0; i < ARRAY_LENGTH; i++){
        printf("%-3d ", arr[i]);
    }
    printf("]");
    
    //reversig array
    for (int i = 0, j = ARRAY_LENGTH-1; i < j; i++, j--){
        arr[i] = arr[i] + arr[j];
        arr[j] = arr[i] - arr[j];
        arr[i] = arr[i] - arr[j];
    }

    printf("\nReversed Array : [ ");
    for (int i = 0; i < ARRAY_LENGTH; i++){
        printf("%-3d ", arr[i]);
    }
    printf("]\n");
    
    return SUCCESS;
}