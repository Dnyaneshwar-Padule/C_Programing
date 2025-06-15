#include<stdio.h>
#define SUCCESS 0

void swap(int*, int*);

int main()
{
    int a = 50, b = 60;
    printf("Before swapping, a : %d, b : %d.\n", a, b);
    swap(&a, &b);
    printf("After  swapping, a : %d, b : %d.\n", a, b);
    return SUCCESS;
}

void swap(int *a, int *b)
{
    *a = *a + * b;
    *b = *a - *b;
    *a = *a - *b;
}
