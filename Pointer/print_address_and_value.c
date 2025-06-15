#include <stdio.h>

int main() {
    int a = 10;
    int *ptr = &a;

    printf("Value of a: %d\n", *ptr);
    printf("Address of a: %p\n", ptr);

    return 0;
}
