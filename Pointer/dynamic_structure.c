#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    float marks;
};

typedef struct Student student;

int main() {

    student *s = (student*)malloc(sizeof(student));
    s->id = 101;
    s->marks = 89.5;
    printf("ID: %d, Marks: %.2f\n", s->id, s->marks);

    free(s);
    return 0;
}
