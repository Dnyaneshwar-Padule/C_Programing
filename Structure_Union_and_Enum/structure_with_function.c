#include<stdio.h>
#define SUCCESS 0

struct student{
    char name[32];
    int roll_number;
    int marks;
};

typedef struct student Student;

void display(Student student){
    printf("Name    : %s\n", student.name);
    printf("Roll no : %d\n", student.roll_number);
    printf("Marks   : %d\n", student.marks);
}

int main(){
    Student student = {"Dnyaneshwar", 49, 94};
    display(student);
    return SUCCESS;
}