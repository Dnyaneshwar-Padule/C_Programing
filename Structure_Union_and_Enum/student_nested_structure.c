#include<stdio.h>
#include<string.h>

#define SUCCESS 0

struct date{
    int year;
    short month;
    char day; // Using it as tiny-int
};
typedef struct date Date;

struct student{
    char name[32];
    Date birth_date;
};
typedef struct student Student;

int main(){
    Student student;

    printf("Enter the name of student : ");
    fgets(student.name, 32, stdin);
    student.name[strlen(student.name) - 1] = '\0';

    printf("Enter the year  of DOB : ");
    scanf("%d", &student.birth_date.year);

    printf("Enter the month of DOB : ");
    scanf("%hd", &student.birth_date.month);
    
    printf("Enter the  day  of DOB : ");
    scanf("%d", &student.birth_date.day);

    printf("\nStudent details\n");
    printf("Name : %s\n", student.name);
    printf("Date of birth : %02d/%02hu/%4d\n", student.birth_date.day, student.birth_date.month, student.birth_date.year);

    return SUCCESS;

}
