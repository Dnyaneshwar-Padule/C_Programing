#include<stdio.h>
#define SUCCESS 0

struct student{
    char name[32];
    int roll_number;
    int marks;
};

typedef struct student Student;

Student get_student(){
    Student student = {"Dnyaneshwar", 49, 94};
    return student;
}

int main(){
    Student student = get_student();
    printf("Name    : %s\n", student.name);
    printf("Roll no : %d\n", student.roll_number);
    printf("Marks   : %d\n", student.marks);
    return SUCCESS;
}