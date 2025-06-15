#include <stdio.h>

enum DataType { INT, FLOAT, CHAR };

union Value {
    int i;
    float f;
    char c;
};

int main() {
    union Value val;
    enum DataType type;

    // Float: 5.50
    // type = FLOAT;
    // val.f = 5.5;

    //Integer: 100
    // type = INT;
    // val.i = 100;

    //Char: A
    type = CHAR;
    val.c = 'A';

    if (type == INT)
        printf("Integer: %d\n", val.i);
    else if (type == FLOAT)
        printf("Float: %.2f\n", val.f);
    else if (type == CHAR)
        printf("Char: %c\n", val.c);

    return 0;
}
