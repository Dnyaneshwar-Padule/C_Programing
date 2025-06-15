#include<stdio.h>
#define SUCCESS 0
#define ARRAY_LENGTH 10

int main(){
    //int arr[] = {1,2,0,5,3,6,4,0,9,0};
    // int arr[] = {1,2,0,5,3,6,4,0,0,0};
    int arr[] = {1,0,0,5,3,6,4,0,0,9};

    printf("\nInitial Array : [");
    for (int i = 0; i < ARRAY_LENGTH; i++){
        printf("%-3d", arr[i]);
    }
    printf("]");
    
    for (int i = 0, j = ARRAY_LENGTH - 1; i < j ; i++){
        if (!arr[i]){

            while (i < j && ! arr[j])
                j--;
            
            arr[i] = arr[i] + arr[j];
            arr[j] = arr[i] - arr[j];
            arr[i] = arr[i] - arr[j];
            j--;
        }
    }
    
    printf("\nArray after shifting all zeros: [");
    for (int i = 0; i < ARRAY_LENGTH; i++){
        printf("%-3d", arr[i]);
    }
    printf("]\n");

    return SUCCESS;
}