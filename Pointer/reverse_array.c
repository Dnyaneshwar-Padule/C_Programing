#include<stdio.h>

void reverse_array(int*, int);

int main(){

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int len = 10;
    
    printf("\nOriginal Array\n");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    reverse_array(arr, len);

    printf("\nReversed Array\n");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

void reverse_array(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
