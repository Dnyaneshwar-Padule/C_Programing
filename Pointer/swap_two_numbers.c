#include<stdio.h>

void swap(int*, int*);

int main(){

    int a = 20, b = 40;
    
    printf("Before swap \n");
    printf("a: %d\nb: %d\n", a, b);
    
    swap(&a, &b);

    printf("After swap \n");
    printf("a: %d\nb: %d\n", a, b);

    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
