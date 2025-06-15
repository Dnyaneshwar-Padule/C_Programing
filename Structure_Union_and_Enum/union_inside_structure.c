#include <stdio.h>

struct Student {
    int id;
    char name[20];
    union {
        int marks;
        char grade;
    } result;
};

int main() {
    struct Student s1 = {101, "Athrva"};
    s1.result.grade = 'A';

    printf("Student ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("Grade: %c\n", s1.result.grade);
    
    s1.result.marks = 87;
    printf("\nStudent ID: %d\n", s1.id);
    printf("Name: %s\n", s1.name);
    printf("Marks: %d\n", s1.result.marks);

    return 0;
}
