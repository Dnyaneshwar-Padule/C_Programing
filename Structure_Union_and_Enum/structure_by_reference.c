#include<stdio.h>
#include<string.h>
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

void modify(Student* student){
    strcpy(student->name,"Athrva");
    student->roll_number = 38;
    student->marks = 86.60;
}

int main(){
    Student student = {"Dnyaneshwar", 49, 88};

    printf("\nInitial data\n");
    display(student);
    modify(&student);
    printf("\nAfter modifying\n");
    display(student);
    
    return SUCCESS;
}