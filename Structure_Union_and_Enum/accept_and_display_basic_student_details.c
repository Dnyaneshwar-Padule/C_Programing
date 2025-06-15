#include<stdio.h>
#include<string.h>

#define SUCCESS 0
#define TRUE 1

struct student{
    char name[32];
    int roll_number;
    int marks;
};

typedef struct student Student;

void clear_buffer(){
    char ch;
    while ( (ch = getchar()) != '\n' && ch != EOF );
    
}

int main(){
    Student students[50];
    int i = 0;
    int choice = 0;

    while (TRUE){
        printf("\nPress '1' to enter a record : ");
        if (! scanf("%d", &choice)){
            printf("Invalid input !\n");
            break;
        }
        clear_buffer();
        if (choice == 1){
            printf("Enter  the  name  of  student : ");
            fgets(students[i].name, 32, stdin);
            students[i].name[strlen(students[i].name) - 1] = '\0';

            printf("Enter the roll no. of student : ");
            scanf("%d", &students[i].roll_number);

            printf("Enter  the  marks  of student : ");
            scanf("%d", &students[i].marks);
            i++;
        }
        else{
            printf("Invalid input !\n");
            break;
        }
    }

    if (i) {
        printf("\n+----------------+-------------+-------+\n");
        printf("|      Name      | Roll Number | Marks |\n");
        printf("+----------------+-------------+-------+\n");
        while (i--){
            printf("| %-14s | %-11d | %-5d |\n", students[i].name, students[i].roll_number, students[i].marks);
        }
        printf("+----------------+-------------+-------+\n");
    }
    else{
        printf("No student record !\n");
    }
    

    return SUCCESS;
    
}