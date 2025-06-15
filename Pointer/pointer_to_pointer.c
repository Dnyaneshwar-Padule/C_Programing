#include<stdio.h>

int main() {
    
    int x = 5;
    int *p = &x;
    int **pp = &p;

    printf("Value of x: %d\n", **pp);

    return 0;
}
