#include<stdio.h>
#include<string.h>

#define SUCCESS 0

struct address{
    char pin_code[10];
    char city[32];
};
typedef struct address Address;

struct student{
    char name[32];
    Address address;
};
typedef struct student Student;

int main(){
    Student student;

    printf("Enter the name of student : ");
    fgets(student.name, 32, stdin);
    student.name[strlen(student.name) - 1] = '\0';
    
    printf("Enter the city  : ");
    fgets(student.address.city, 32, stdin);
    student.address.city[strlen(student.address.city) - 1] = '\0';
    
    printf("Enter the PIN  : ");
    fgets(student.address.pin_code, 10, stdin);
    student.address.pin_code[strlen(student.address.pin_code) - 1] = '\0';

    printf("\nStudent details\n");
    printf("Name : %s\n", student.name);
    printf("City : %s\n", student.address.city);
    printf("PIN  : %s\n", student.address.pin_code);

    return SUCCESS;

}
