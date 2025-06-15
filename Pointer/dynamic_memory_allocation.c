#include<stdio.h>
#include <stdlib.h>

int *create_array(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;
    return arr;
}

int main(){
    int* arr = create_array(10);

    printf("\nArray\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
