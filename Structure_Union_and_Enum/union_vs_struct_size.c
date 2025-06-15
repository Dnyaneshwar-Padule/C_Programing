#include <stdio.h>

struct MyStruct {
    int i;
    float f;
    char c;
};

union MyUnion {
    int i;
    float f;
    char c;
};

int main() {
    printf("Size of struct: %lu\n", sizeof(struct MyStruct)); // Output: 12 (or more due to padding)
    printf("Size of union : %lu\n", sizeof(union MyUnion));   // Output: 4
    
    return 0;
}
